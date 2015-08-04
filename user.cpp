#include "user.h"
//#include "database.h" per evitare loop compilativi

User::User(const QString & typ,
           Database* ptrDb)
    : valid(true), UserType(typ), db(ptrDb)
{}

User::~User() {}


QString& User::getType(){

    return UserType;
}

const QString & User::cgetType() const{

    return UserType;
}

void User::setAccountValid(const bool & newValid){

    valid = newValid;
}

void User::setAccountType(const QString & newType){

    UserType = newType;
}


bool User::isValid()const{

    return valid;
}


int & User::getRef(){

    return ref;
}

const int & User::cgetRef()const{

    return ref;
}

Database * User::getDb()const{

    return db;
}

void User::setDb(Database * newDb){

    db = newDb;
}
