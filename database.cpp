#include "database.h"

Database::Database() : state(ok)
{}

Database::~Database() {}


DataMember& Database::getDb(){

    return db;
}

const DataMember& Database::cgetDb() const{

    return db;
}

ViewerPair & Database::getView(){

    return usrView;
}

const ViewerPair & Database::cgetView()const{

    return usrView;
}

//FUNZIONI DI RICERCA

DataMember& Database::select(const Profile & find)const{

    /*
     * Nota: viene passato un Profile quando le experiences non vengono
     * controllate. Si potrebbe passare direttamente un Personal, ma tengo
     * Profile perchè se un domani implemento la ricerca anche per
     * le Experiences non devo modificare i parametri passati alla funzione.
     */

    bool checkname = false;
    bool checksurn = false;
    bool checkbirt = false;

    QRegularExpression nameRe;
    QRegularExpression surnameRe;
    QRegularExpression birthRe;

    DataMember* pres = new DataMember();

    const Bio & fbio = find.cgetPersonal().cgetBio();

    QString name = fbio.getName();
    if (name.size() > 0){

        checkname = true;

        name = "([\\d+\\w+])*("+name+")([\\d+\\w+])*";
        nameRe.setPattern(name);
        nameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }


    QString surname = fbio.getSurname();
    if (surname.size() > 0){

        checksurn = true;

        surname = "([\\d+\\w+])*("+surname+")([\\d+\\w+])*";
        surnameRe.setPattern(surname);
        surnameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }

    QString birthDay = fbio.getBirthday().toString("dd-MM-yyyy");
    if (birthDay.size() > 0){

        checkbirt = true;

        birthDay = "([\\d+\\w+])*("+birthDay+")([\\d+\\w+])*";
        birthRe.setPattern(birthDay);
        birthRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }


    DataMember::const_iterator it;

    for (it = db.cbegin(); it != db.cend(); ++it){

        const SmartMember & current = db[it];

        if (current->isValid() == true){ //solo se è valido

            const Profile & pcurrent = current->cgetProfile();

            const Hobby & chbb = pcurrent.cgetPersonal().cgetHobby();
            const Hobby & fhbb = find.cgetPersonal().cgetHobby();

            const Interests & cint = pcurrent.cgetPersonal().cgetInterests();
            const Interests & fint = find.cgetPersonal().cgetInterests();

            bool sameHI = true;

            Hobby::const_iterator ith;
            for (ith = fhbb.cbegin(); ith != fhbb.cend() &&
                 sameHI == true; ++ith){

                const QString & target = fhbb[ith];
                if (chbb.contains(target) == false)
                    sameHI = false;
            }


            Interests::const_iterator iti;
            for (iti = fint.cbegin(); iti != fint.cend() &&
                 sameHI == true; ++iti){

                const QString & target = fint[iti];
                if (cint.contains(target) == false)
                    sameHI = false;
            }

            if (sameHI == true){

                const Bio & cbio = pcurrent.cgetPersonal().cgetBio();

                const QString& cname = cbio.getName();
                const QString& csurn = cbio.getSurname();
                const QString& birth = cbio.getBirthday().toString("dd-MM-yyyy");

                bool ismname = true;
                if (checkname == true){
                    QRegularExpressionMatch mname = nameRe.match(cname);

                    if (mname.hasMatch() == false)
                        ismname = false;
                }


                bool ismsurn = true;
                if (checksurn == true){
                    QRegularExpressionMatch msurn = surnameRe.match(csurn);

                    if (msurn.hasMatch() == false)
                        ismsurn = false;
                }


                bool ismbirth = true;
                if (checkbirt == true){
                    QRegularExpressionMatch mbirth = birthRe.match(birth);

                    if (mbirth.hasMatch() == false)
                        ismbirth = false;
                }


                if (ismname == true && ismsurn == true && ismbirth == true)
                    pres->add(current);
            }

        }

    }

    return *pres;
}

const SmartMember& Database::cselect (const QString & find)const{

    DataMember::const_iterator it = db.cbegin();

    bool match = false;

    while (match == false && it != db.cend()){

        const QString & check = (*it)->cgetCredential().getCredential();

        if (check == find){
            match = true;
        }else
            ++it;
    }

    if (match == true){
        return *it;
    }else{
        SmartMember* ptr = new SmartMember();
        return *ptr;
    }

}

SmartMember& Database::select (const QString & find){

    DataMember::iterator it = db.begin();

    bool match = false;

    while (match == false && it != db.end()){ //vedi nota sopra

        const QString & check = (*it)->cgetCredential().getCredential();

        if (check == find){
            match = true;
        }else
            ++it;
    }

    if (match == true){
        return *it;
    }else{
        SmartMember* ptr = new SmartMember();
        return *ptr;
    }
}

//ERRORI DB
bool Database::isOk()const{
    dbState confront = ok;

    if (state == confront)
        return true;

    return false;
}

bool Database::isRead_only()const{
    dbState confront = read_only;

    if (state == confront)
        return true;

    return false;
}

bool Database::isBad_db()const{
    dbState confront = bad_db;

    if (state == confront)
        return true;

    return false;
}

bool Database::isGeneric_error()const{
    dbState confront = generic_error;

    if (state == confront)
        return true;

    return false;
}

void Database::setState(dbState newState){

    state = newState;
}
