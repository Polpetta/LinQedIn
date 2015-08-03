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

/*bool Database::matchHobby(const Profile & pcurrent, const Profile & find)const{

    //controllo gli hobby
    Hobby::const_iterator ith;

    bool matchHobby = true;
    for (ith = pcurrent.cgetPersonal().cgetHobby().cbegin();
         ith != pcurrent.cgetPersonal().cgetHobby().cend();
         ++ith){

        QString & hobby = pcurrent.cgetPersonal().cgetHobby()[ith];
        hobby = "/"+hobby+"/";
        QRegularExpression hobbyRe(hobby,
                                   QRegularExpression::CaseInsensitiveOption);


        Hobby::const_iterator ithf;

        for (ithf = find.cgetPersonal().cgetHobby().cbegin();
             ithf != find.cgetPersonal().cgetHobby().cend() &&
             matchHobby == true;
             ++ithf){

            QString & fHobby = find.cgetPersonal().cgetHobby()[ithf];

            QRegularExpressionMatch match = hobbyRe.match(fHobby);
            if (match.hasMatch() == false)
                matchHobby = false;
        }
    }

    return matchHobby;
}*/

DataMember* Database::select(const Profile & find)const{

    DataMember* pres = new DataMember();

    QString name = find.cgetPersonal().cgetBio().getName();
    name = "/"+name+"/";
    QRegularExpression nameRe (name, QRegularExpression::CaseInsensitiveOption);

    QString surname = find.cgetPersonal().cgetBio().getSurname();
    surname = "/"+surname+"/";
    QRegularExpression surnameRe (surname, QRegularExpression::CaseInsensitiveOption);

    QString birthDay = find.cgetPersonal().cgetBio().getBirthday().toString("dd-MM-yyyy");
    birthDay = "/"+birthDay+"/";
    QRegularExpression birthRe (birthDay, QRegularExpression::CaseInsensitiveOption);


    DataMember::const_iterator it;

    for (it = db.cbegin(); it != db.cend(); ++it){

        const SmartMember & current = db[it];
        const Profile & pcurrent = current->cgetProfile();

        bool matchHobby = false;
        if (pcurrent.cgetPersonal().cgetHobby() == find.cgetPersonal().cgetHobby())
            matchHobby = true;

        /*//controllo gli interessi
        Interests::const_iterator iti;

        bool matchInterests = true;
        for (iti = find.cgetPersonal().getInterests().cbegin();
             iti != find.cgetPersonal().getInterests().cend();
             ++iti){

            QString & interests = pcurrent.cgetPersonal().cgetInterests()[iti];
            interests = "/"+interests+"/";
            QRegularExpression interestsRe(interests,
                                           QRegularExpression::CaseInsensitiveOption);


            Interests::const_iterator itif;

            for (itif = find.cgetPersonal().cgetInterests().cbegin();
                 itif != find.cgetPersonal().cgetInterests().cend();
                 ++itif){

                QString & fInterests = find.cgetPersonal().cgetHobby()[itif];

                QRegularExpressionMatch match = interestsRe.match(fInterests);
                if (match.hasMatch() == false)
                    matchInterests = false;
            }
        }*/

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
