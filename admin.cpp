#include "admin.h"

Admin::Admin(const Credentials & crd,
             const QString & typ)
    : User (crd,typ)
{}

Admin::~Admin() {}

UserData & Admin::search (const QString & target)const{

    //da implementare
}

 void Admin::save(QXmlStreamWriter & write) const{

    /*
     * Cosa da salvare:
     * -Credentials
     */

    //write.writeStartElement(); scrivere "titolo" dati
    //write.writeTextElement(); scrivere dati
    //write.writeEndElement(); chiude sezione dati

    //CREDENTIALS
    const Credentials & tcrd = cgetCredential();

    write.writeStartElement("Credentials");
    write.writeTextElement("nick", tcrd.getCredential());
    write.writeEndElement();
    //END CREDENTIALS
}

void Admin::saveBack(QXmlStreamWriter & write) const{

    //non ho da scrivere niente, lascio vuota
}

void Admin::load(QXmlStreamReader & read){

    //da implementare
}

void Admin::loadBack(QXmlStreamReader & read){

    //nulla da leggere successivamente
}

void Admin::addUser(Database* db,const SmartUser & newUser) const{

    db->getDb().add(newUser);
}
