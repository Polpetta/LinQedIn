#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "database.h"
#include "smartmember.h"

#include "memberexecutive.h"

/*
 * Richieste per il progetto:
 * -Inserimento nel DB di un nuovo utente
 * -Ricerca nel DB di un utente mediante nome/cognome o codice
 * -Rimozione del DB di un utente Linkedin
 * -Cambio tipologia di account per un utente Linkedin
 * -Salvataggio/lettura sul file del DB degli utenti
 */

class Admin : public User
{
public:
    Admin(const QString & = QString());

    virtual ~Admin();

    virtual DataMember & search(const QString &) const;

    //funzioni proprie dell'admin
    void addMember (Database*, const SmartMember &) const;
    void rmMember (Database*, const SmartMember &)const;

    void changeMemberType (SmartMember &, const QString &)const;
};

#endif // ADMIN_H
