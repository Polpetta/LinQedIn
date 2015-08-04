#include "user.h"

User::User(const QString & typ)
    : valid(true), UserType(typ)
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
