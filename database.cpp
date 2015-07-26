#include "database.h"

Database::Database() : state(ok)
{}

Database::~Database() {}

void Database::add(const SmartUtente & newUser) {

    db.push_back(newUser);
}

void Database::remove(const SmartUtente & target) {
    //DA RIVEDERE
    /*
     * Da rivedere in quanto bisogna controllare come si comporta la
     * RAM in queste situazioni.
     */


    vector<SmartUtente>::iterator it;

    for (it = db.begin(); it != db.end(); ++it){

        if (*it == target){

            SmartUtente last = db.back();
            db.pop_back();

            *it = last;
        }
    }
}


bool Database::isOk()const{

    if (state == dbState::ok)
        return true;

    return false;
}

bool Database::isRead_only()const{

    if (state == dbState::read_only)
        return true;

    return false;
}

bool Database::isBad_db()const{

    if (state == dbState::bad_db)
        return true;

    return false;
}

bool Database::isGeneric_error()const{

    if (state == dbState::generic_error)
        return true;

    return false;
}

void Database::setState(dbState newState){

    state = newState;
}
