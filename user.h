#ifndef USER_H
#define USER_H

#include "credentials.h"

class User
{
public:
    User(const Credentials & = Credentials());

    virtual ~User();

    virtual User& search(const QString &) const =0;

    Credentials & getCredential();
    const Credentials & cgetCredential()const;

    void setCredential(const Credentials &);

private:

    Credentials logCrd;

    //ci andrà anche l'oggetto search qui che è ancora da creare
};

#endif // USER_H
