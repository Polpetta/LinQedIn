#include "user.h"

User::User(const Credentials & secrets)
    : logCrd(secrets)
{}

User::~User() {}


const Credentials & User::getCredential()const{

    return logCrd;
}

void User::setCredential (const Credentials & replace){

    logCrd = replace;
}
