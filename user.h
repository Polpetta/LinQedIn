#ifndef USER_H
#define USER_H

#include "credentials.h"

class User
{
public:
    User(const Credentials & = Credentials());

    virtual ~User();

    virtual User& search(const QString &) const =0;

    const Credentials & getCredential()const;

    void setCredential(const Credentials &);

private:

    Credentials logCrd;

    //ci andrà anche l'oggetto search qui che è ancora da creare
};

#endif // USER_H
