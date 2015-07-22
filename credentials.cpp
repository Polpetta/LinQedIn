#include "credentials.h"

Credentials::Credentials(const QString & usr) : nick(usr)
{}

const QString & Credentials::getCredential () const{

    return nick;
}
