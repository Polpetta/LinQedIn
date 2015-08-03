#include "admin.h"

Admin::Admin(const Credentials & crd,
             const QString & typ)
    : User (crd,typ)
{}

Admin::~Admin() {}

DataMember & Admin::search (const QString & target)const{

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

void Admin::addMember(Database* db,const SmartMember & newUser) const{

    db->getDb().add(newUser);
}

void Admin::rmMember (Database *db, const SmartMember & target) const{

    db->getDb().rm(target);
}

void Admin::changeMemberType(SmartMember & oldMember, const QString &newType)const{

    if (oldMember->cgetType() != newType){

        /*Member* oldMbr = dynamic_cast<Member*>(oldMember.getPunt());
        if (oldMbr == 0){

            return; //dynamic_cast non è andato a buon fine
        }*/

        SmartMember newMember;

        if (newType == "Basic"){

            newMember = new MemberBasic(oldMember->cgetCredential(),
                                        newType,
                                        oldMember->cgetProfile(),
                                        oldMember->cgetFriendships());
        }
        else if (newType == "Business"){

            newMember = new MemberBusiness(oldMember->cgetCredential(),
                                           newType,
                                           oldMember->cgetProfile(),
                                           oldMember->cgetFriendships());
        }
        else if (newType == "Executive"){

            newMember = new MemberExecutive(oldMember->cgetCredential(),
                                            newType,
                                            oldMember->cgetProfile(),
                                            oldMember->cgetFriendships());
        }

        //disattivo l'account "vecchio"
        oldMember->setAccountValid(false);

        oldMember = newMember;
        /* Non mi devo preoccupare di che fine fa l'oggetto puntato da
         * oldMember perchè esso viene eliminato dalla classe SmartUser.
         * Inoltre oldMbr potrebbe costituire dangling pointer in caso
         * l'oggetto a cui puntava oldMember venisse eliminato, ma alla
         * fine della funzione esso verrà deallocato (il puntatore) e
         * comunuque non viene più dereferenziato.
         *
         * Questo codice porta a dei problemi però: infatti tutti gli altri
         * utenti che hanno lui come amico continueranno a vedere il
         * profilo vecchio della persona (ovvero l'account primo del
         * cambiamento di tipologia, in quanto puntano all'"account"
         * vecchio). Bisognerebbe aggiornare tutta la rete di amicizie in
         * cui è presente questo utente o ricaricare il db. <=da rivedere
         * Oppure si potrebbe fare la liste di amicizie come una serie di
         * nickname che mi vado a ricercare ogni volta (+ dispendioso ma
         * si evita questo problema)
         */
    }
}
