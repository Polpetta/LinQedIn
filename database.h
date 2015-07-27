#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "smartutente.h"
#include "userdata.h"

using std::vector;

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

    virtual void save() =0; //il vector viene scritto su file
    virtual void load() =0; //carica tutto il db

    UserData& getDb();
    const UserData& cgetDb() const; //per sola lettura
    /*
     * Nota: UserData è definito esterno perchè così la funzione
     * search può ritornare un UserData (che sarà un sottoinsieme
     * del db) e quindi c'è un unica implementazione per la gestione
     * di tutti i dati o sottoinsiemi di dati del db.
     */

    //virtual void add (const SmartUtente &); //aggiunge un singolo utente
    //virtual void remove (const SmartUtente &); //rimuove un utente singolo

    virtual UserData & search (const User &) =0;
    /*Qui forse non è cosa buona e giusta passare un intero User
     * perchè ci sarebbe un sacco di utilizzo di memoria. Forse
     * sarebbe meglio creare una gerarchia di classe "criteria" che
     * in base al tipo di utente che effettua la ricerca
     * contiene solamente i dati necessari.
     * È necessario sia virtual? Si potrebbe implementare a questo
     * livello?
     */

    //stati del db
    bool isOk() const;
    bool isRead_only() const;
    bool isBad_db() const;
    bool isGeneric_error() const;
    void setState(dbState =ok); //pone state a 0

private:

    UserData db;
    dbState state;


};

#endif // DATABASE_H
