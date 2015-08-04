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

//FUNZIONI DI RICERCA

DataMember* Database::select(const Profile & find)const{

    bool checkname = false;
    bool checksurn = false;
    bool checkbirt = false;

    QRegularExpression nameRe;
    QRegularExpression surnameRe;
    QRegularExpression birthRe;

    DataMember* pres = new DataMember();

    QString name = find.cgetPersonal().cgetBio().getName();
    if (name.size() > 0){

        checkname = true;

        name = "/"+name+"/";
        nameRe.setPattern(name);
        nameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }


    QString surname = find.cgetPersonal().cgetBio().getSurname();
    if (surname.size() > 0){

        checksurn = true;

        surname = "/"+surname+"/";
        surnameRe.setPattern(surname);
        surnameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }

    QString birthDay = find.cgetPersonal().cgetBio().getBirthday().toString("dd-MM-yyyy");
    if (birthDay.size() > 0){

        checkbirt = true;

        birthDay = "/"+birthDay+"/";
        birthRe.setPattern(birthDay);
        birthRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    }


    DataMember::const_iterator it;

    for (it = db.cbegin(); it != db.cend(); ++it){

        const SmartMember & current = db[it];
        const Profile & pcurrent = current->cgetProfile();

        const Hobby & chbb = pcurrent.cgetPersonal().cgetHobby();
        const Hobby & fhbb = find.cgetPersonal().cgetHobby();

        const Interests & cint = pcurrent.cgetPersonal().cgetInterests();
        const Interests & fint = find.cgetPersonal().cgetInterests();

        bool sameHI = true;
        if (fhbb.size() > 0 && fint.size() > 0)
            if (chbb != fhbb || cint != fint)
                sameHI = false;

        if (sameHI == true){

            const QString& cname = pcurrent.cgetPersonal().cgetBio().getName();
            const QString& csurn = pcurrent.cgetPersonal().cgetBio().getSurname();
            const QString& birth = pcurrent.cgetPersonal().cgetBio().getBirthday().toString("dd-MM-yyyy");

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



            //bisogna controllare le esperienze prima di fare questa cosa!
            if (ismname == true &&
                    ismsurn == true &&
                    ismbirth == true)
                pres->add(current);

        }

    }

    return pres;
}

const SmartMember& Database::cselect (const QString & find)const{

    DataMember::const_iterator  it;

    bool match = false;

    for (it = db.cbegin(); it != db.cend() && !match; ++it){

        const QString & check = (*it)->cgetCredential().getCredential();

        if (check == find)
            match = true;
    }

    return *it;
}

SmartMember& Database::select(const QString & find){

    DataMember::iterator it;

    bool match = false;

    for (it = db.begin(); it != db.end() && !match; ++it){

        const QString & check = (*it)->cgetCredential().getCredential();

        if (check == find)
            match = true;
    }

    return *it;
}


const SmartMember& Database::cselect(const SmartMember & check) const{

    DataMember::const_iterator it;

    bool match = false;

    for (it = db.cbegin(); it != db.cend() && !match; ++it){

        if (*it == check)
            match = true;
    }

    return *it;
}

SmartMember& Database::select(const SmartMember & check){

    DataMember::iterator it;

    bool match = false;

    for (it = db.begin(); it != db.end() && !match; ++it){

        if (*it == check)
            match = true;
    }

    return *it;
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
