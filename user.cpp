#include "user.h"

User::User(const Credentials & secrets)
    : logCrd(secrets)
{}

User::~User() {}



Credentials & User::getCredential(){

    return logCrd;
}

const Credentials & User::cgetCredential()const{

    return logCrd;
}

void User::setCredential (const Credentials & replace){

    logCrd = replace;
}
