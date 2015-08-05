#include "member.h"

Member::Member(const Credentials & crd,
               const QString & typ,
               const Profile & prf,
               const Friendships & frnd,
               Database* ptr)

    : User(typ,ptr), logCrd(crd), info(prf), friends(frnd)
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

Credentials & Member::getCredential(){

    return logCrd;
}

const Credentials & Member::cgetCredential()const{

    return logCrd;
}

void Member::setCredential (const Credentials & replace){

    logCrd = replace;
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

        const SmartMember & friendof = getDb()->cselect((*itf));

        if (friendof.cgetPunt() != nullptr && friendof->isValid() == true)
            write.writeTextElement("FriendOf",friendof->cgetCredential().getCredential());
        //Questo mi serve a controllare se c'è l'amico nel db e se è valido
    }

    write.writeEndElement();
    //END FRIENDSHIPS
}


void Member::load(QXmlStreamReader & read){

    read.readNextStartElement();
    qDebug()<<read.name();

    //PROFILE
    if (read.name() == "Profile"){

        read.readNextStartElement();
        qDebug()<<read.name();
        //PERSONAL
        if (read.name() == "Personal"){

            read.readNextStartElement();
            qDebug()<<read.name();
            //BIO
            if (read.name() == "Bio"){

                Bio newBio;

                read.readNextStartElement();
                QDate birth(
                            QDate::fromString(
                                read.readElementText(), "dd-MM-yyyy"));
                qDebug()<<"Data: "<<birth;

                newBio.setBirthday(birth);

                read.readNextStartElement();
                newBio.setName(read.readElementText());
                qDebug()<<"Nome: "<<newBio.getName();

                read.readNextStartElement();
                newBio.setSurname(read.readElementText());
                qDebug()<<"Surname: "<<newBio.getSurname();

                read.readNextStartElement();
                newBio.setPhone(read.readElementText());
                qDebug()<<"Phone: "<<newBio.getPhone();

                read.readNextStartElement();
                newBio.setMail(read.readElementText());
                qDebug()<<"eMail: "<<newBio.getMail();

                getProfile().getPersonal().setBio(newBio);
            }

            read.skipCurrentElement();
            //END BIO

            read.readNextStartElement();
            qDebug()<<read.name();
            //HOBBY
            if(read.name() == "Hobby"){

                read.readNextStartElement();
                qDebug()<<read.name();
                while (read.name() == "Info"){

                    const QString & newHbb = read.readElementText();
                    qDebug()<<"Tipo di Hobby: "<<newHbb;

                    getProfile().getPersonal().getHobby().add(newHbb);

                    read.readNextStartElement();

                }
            }

            read.skipCurrentElement();
            //END HOBBY

            read.readNextStartElement();
            qDebug()<<read.name();
            //EXPERIENCES
            if (read.name() == "Experiences"){

                read.readNextStartElement();
                qDebug()<<read.name();
                while (read.name() == "Event"){

                    read.readNextStartElement();

                    QDate begin(QDate::fromString(
                                    read.readElementText(),
                                    "dd-MM-yyyy"));
                    qDebug()<<read.name()<<": "<<begin;


                    read.readNextStartElement();

                    QDate finish(QDate::fromString(
                                     read.readElementText(),
                                     "dd-MM-yyyy"));
                    qDebug()<<read.name()<<": "<<finish;


                    read.readNextStartElement();

                    QString desc = read.readElementText();
                    qDebug()<<read.name()<<": "<<desc;


                    read.readNextStartElement();

                    QString where = read.readElementText();
                    qDebug()<<read.name()<<": "<<where;

                    Event newEv (begin,
                                 finish,
                                 desc,
                                 where);

                    getProfile().getExperiences().add(newEv);

                    read.skipCurrentElement();
                    read.readNextStartElement();

                }

            }

            read.skipCurrentElement();
            //END EXPERIENCES & PROFILE

        }
    }

}

void Member::loadBack(QXmlStreamReader & read){
    //da fare

}
