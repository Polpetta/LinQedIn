#ifndef DATABASE_H
#define DATABASE_H

#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "viewerpair.h"
#include "datamember.h"
#include "smartmember.h"
#include "profile.h"
#include "member.h"

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
    virtual void save() =0; //il db viene scritto
    virtual void load() =0; //carica tutto il db

    DataMember& getDb();
    const DataMember& cgetDb() const; //per sola lettura

    ViewerPair & getView();
    const ViewerPair & cgetView()const;
    /*
     * Nota: DataMember è definito esterno perchè così la funzione
     * search può ritornare un DataMember (che sarà un sottoinsieme
     * del db) e quindi c'è un unica implementazione per la gestione
     * di tutti i dati o sottoinsiemi di dati del db.
     */

    virtual DataMember& select (const Profile &)const;
    /*
     * È necessario sia virtual perchè se in un futuro una classe derivata
     * volesse dare una implementazione migliore o fosse vantaggioso
     * direttamente cercare sulla memoria di massa piuttosto che caricare in ram
     * così avrei la possibiltà di farlo
     */
    virtual const SmartMember& cselect (const QString &)const;
    virtual SmartMember& select (const QString &);

    //stati del db
    bool isOk() const;
    bool isRead_only() const;
    bool isBad_db() const;
    bool isGeneric_error() const;
    void setState(dbState =ok); //pone state a 0

private:

    DataMember db;
    dbState state;
    ViewerPair usrView;



};

#endif // DATABASE_H
