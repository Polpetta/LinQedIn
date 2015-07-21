#include "user.h"

User::User(const QString & usr,
           const QString & pswd)
    : nick(usr),
      password(pswd)
{}

User::~User() {}
