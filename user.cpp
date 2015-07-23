#include "user.h"

User::User(const Credentials & secrets,
           const QString & typ)
    : logCrd(secrets), UserType(typ)
{}

User::~User() {}


QString& User::getType(){

    return UserType;
}

const QString & User::cgetType() const{

    return UserType;
}

Credentials & User::getCredential(){

    return logCrd;
}

const Credentials & User::cgetCredential()const{

    return logCrd;
}

void User::setCredential (const Credentials & replace){

    logCrd = replace;
}

void User::setAccountValid(const bool & newValid){

    valid = newValid;
}


bool User::isValid()const{

    return valid;
}
