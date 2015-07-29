#include "member.h"

Member::Member(const Credentials & crd,
               const QString & typ,
               const Profile & prf,
               const Friendships & frnd)

    : User(crd,typ), info(prf), friends(frnd)
{}

Member::~Member()
{}

Profile & Member::getProfile(){

    return info;
}

const Profile & Member::cgetProfile()const{

    return info;
}

Friendships & Member::getFriendships(){

    return friends;
}

const Friendships & Member::cgetFriendships()const{

    return friends;
}


void Member::setProfile(const Profile & replace){

    info = replace;
}

void Member::setFrinds(const Friendships & replace){

    friends = replace;
}


//SCRITTURA DI UN ISCRITTO
void Member::save(QXmlStreamWriter & write) const{

    /*
     * Cose da salvare:
     * -Credentials
     * -bool valid => inutile, il costruttore lo setta già a true
     * -Profile
     * -Friendships
     */

    //write.writeStartElement(); scrivere "titolo" dati
    //write.writeTextElement(); scrivere dati
    //write.writeEndElement(); chiude sezione dati

    //CREDENTIALS
    const Credentials & tcrd = cgetCredential();

    write.writeStartElement("Credentials");
    write.writeTextElement("nick", tcrd.getCredential());
    write.writeEndElement();
    //END CREDENTIALS

    //PROFILE
    const Profile & tprf = cgetProfile();

    write.writeStartElement("Profile");
    //Profile -> PERSONAL
    const Personal & tprs = tprf.cgetPersonal();

    write.writeStartElement("Personal");

    //Personal -> BIO
    const Bio & tbio = tprs.cgetBio();

    write.writeStartElement("Bio");
    write.writeTextElement("Birthday", tbio.getBirthday().toString("dd-MM-yyyy"));
    write.writeTextElement("Name", tbio.getName());
    write.writeTextElement("Surname", tbio.getSurname());
    write.writeTextElement("Phone", tbio.getPhone());
    write.writeTextElement("Mail", tbio.getMail());
    write.writeEndElement();
    //END BIO

    //Personal -> HOBBY
    const Hobby & thbb = tprs.cgetHobby();

    write.writeStartElement("Hobby");
    Hobby::const_iterator ith;
    for (ith = thbb.cbegin(); ith != thbb.cend(); ++ith){

        write.writeTextElement("Info", thbb[ith]);
    }
    write.writeEndElement();
    //END HOBBY

    //Personal -> INTERESTS
    const Interests & tint = tprs.cgetInterests();

    write.writeStartElement("Interests");
    Interests::const_iterator iti;
    for(iti = tint.cbegin(); iti != tint.cend(); ++iti){

        write.writeTextElement("Info", tint[iti]);
    }
    write.writeEndElement();
    //END INTERESTS

    write.writeEndElement();
    //END PERSONAL

    //Profile -> EXPERIENCES
    const Experiences & texp = tprf.cgetExperiences();

    write.writeStartElement("Experiences");
    Experiences::const_iterator ite;
    for (ite = texp.cbegin(); ite != texp.cend(); ++ite){

        //Experiences -> EVENT
        const Event & teve = texp[ite];

        write.writeStartElement("Event");
        write.writeTextElement("Begin", teve.cgetBegin().toString("dd-MM-yyyy"));
        write.writeTextElement("Finish", teve.cgetFinish().toString("dd-MM-yyyy"));
        write.writeTextElement("Desc", teve.cgetDesc());
        write.writeTextElement("Where", teve.cgetWhere());

        write.writeEndElement();
        //END EVENT
    }

    write.writeEndElement();
    //END EXPERIENCES

    write.writeEndElement();
    //END PROFILE

    /*
     * Le amicizie conviene scriverle alla fine di tutto in quanto
     * così poi si possono ricreare i puntatori molto più facilmente
     */
}

void Member::saveBack(QXmlStreamWriter & write) const{

    //FRIENDSHIPS
    const Friendships & tfrn = cgetFriendships();

    write.writeStartElement("Friendships");

    Friendships::const_iterator itf;

    for (itf = tfrn.cbegin(); itf != tfrn.cend(); ++itf){

        write.writeTextElement("FriendOf", (*(*itf)).cgetCredential().getCredential());
    }

    write.writeEndElement();
    //END FRIENDSHIPS
}


void Member::load(QXmlStreamReader & read){
    //da fare

}

void Member::loadBack(QXmlStreamReader & read){
    //da fare

}
