#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "smartutente.h"

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
    virtual void add (const SmartUtente &); //aggiunge un singolo utente
    virtual void remove (const SmartUtente &); //rimuove un utente singolo

    virtual vector<SmartUtente> & search (const User &) =0;
    /*Qui forse non è cosa buona e giusta passare un intero User
     * perchè ci sarebbe un sacco di utilizzo di memoria. Forse
     * sarebbe meglio creare una gerarchia di classe "criteria" che
     * in base al tipo di utente che effettua la ricerca
     * contiene solamente i dati necessari */

    //stati del db
    bool isOk() const;
    bool isRead_only() const;
    bool isBad_db() const;
    bool isGeneric_error() const;
    void setState(dbState =dbState::ok); //pone state a 0

protected:
    /*
     * è giusto mettere protected?
     * Potrebbe essere una buona scelta per rendere facilmente
     * accessibile la lista alla classi derivate, ma è una buona
     * implementazione dal punto di vista dell'information hiding?
     * Forse bisogna fare un'altra classe al posto di usare
     * semplicemente un vector? In caso non si usi più un vector,
     * tutte le sottoclassi dovrebbero adattarsi a questo cambiamento
     */
    vector<SmartUtente> db;

private:
    dbState state;
};

#endif // DATABASE_H
