#include "database.h"

Database::Database() : state(ok)
{}

Database::~Database() {}

/*void Database::add(const SmartUtente & newUser) {

    db.push_back(newUser);
}

void Database::remove(const SmartUtente & target) {
    //DA RIVEDERE
    *
     * Da rivedere in quanto bisogna controllare come si comporta la
     * RAM in queste situazioni.
     *


    vector<SmartUtente>::iterator it;

    for (it = db.begin(); it != db.end(); ++it){

        if (*it == target){

            SmartUtente last = db.back();
            db.pop_back();

            *it = last;
        }
    }
}*/


UserData& Database::getDb(){

    return db;
}

const UserData& Database::cgetDb() const{

    return db;
}


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
