#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

//da rimuovere poi
#include <QDebug>

#include "datamember.h"
#include "smartmember.h"
#include "profile.h"
#include "member.h"

using std::vector;

/*
 * Idea: seguo la gerarchia di classi di QT, ovvero:
 * -QIODevice
 * -QFile
 * -XmlStream -> dove staranno effettivamente i dati
 */

class Database
{    
public:
    enum dbState{
        ok = 0, //tutto bene
        read_only = 1, //il db è in sola lettura
        bad_db = 2, //il db è rovinato
        generic_error = 3, //errore generico (sconosciuto)
    };

    Database();
    virtual ~Database();

    //non vanno implementati qui, nella gerarchia più in basso
    virtual void save() =0; //il vector viene scritto su file
    virtual void load() =0; //carica tutto il db

    DataMember& getDb();
    const DataMember& cgetDb() const; //per sola lettura
    /*
     * Nota: DataMember è definito esterno perchè così la funzione
     * search può ritornare un DataMember (che sarà un sottoinsieme
     * del db) e quindi c'è un unica implementazione per la gestione
     * di tutti i dati o sottoinsiemi di dati del db.
     */

    virtual DataMember& select (const Profile &)const;
    /*
     * È necessario sia virtual? Si potrebbe implementare a questo
     * livello?
     */
    virtual const SmartMember& cselect (const QString &)const;
    virtual SmartMember& select (const QString &); //è giusto che non sia cost?

    virtual const SmartMember& cselect (const SmartMember &)const; //dr
    virtual SmartMember& select (const SmartMember &); //da rivedere

    //stati del db
    bool isOk() const;
    bool isRead_only() const;
    bool isBad_db() const;
    bool isGeneric_error() const;
    void setState(dbState =ok); //pone state a 0

private:

    DataMember db;
    dbState state;



};

#endif // DATABASE_H
