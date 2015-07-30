#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "database.h"
#include "smartuser.h"

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
    Admin(const Credentials & = Credentials(),
          const QString & = QString());

    virtual ~Admin();

    virtual UserData & search(const QString &) const;

    virtual void save (QXmlStreamWriter &) const;
    virtual void saveBack (QXmlStreamWriter &) const;

    virtual void load (QXmlStreamReader &);
    virtual void loadBack (QXmlStreamReader &);

    //funzioni proprie dell'admin
    void addUser (Database*, const SmartUser &) const;
    void rmUser (Database*, const QString &)const; //rimozione by nick

    void changeUserType (Database*, const QString &, const QString &);
    void changeUserType (Database*, const SmartUser &, const QString &);
};

#endif // ADMIN_H
