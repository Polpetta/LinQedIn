#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "database.h"
#include "smartmember.h"

#include "memberexecutive.h"

/*
 * -Inserimento nel DB di un nuovo utente
 * -Ricerca nel DB di un utente mediante nome/cognome o codice
 * -Rimozione del DB di un utente Linkedin
 * -Cambio tipologia di account per un utente Linkedin
 */

class Admin : public User
{
public:
    Admin(const QString & = QString(),
          Database* = nullptr);

    virtual ~Admin();

    virtual DataMember & search(const Profile &) const;
    virtual SmartMember & search(const QString &)const;

    //funzioni proprie dell'admin
    void addMember (const SmartMember &) const;
    void rmMember (const SmartMember &)const;

    void changeMemberType (SmartMember &, const QString &)const;
};

#endif // ADMIN_H
