#include "dbonxml.h"

DBonXml::DBonXml(const QString & nameFile)
    : DBonFile(nameFile),
      read (this),
      write (this)
    /*
     * Come costruttori di read e write ho messo this
     * in quanto i loro costruttori accettano un QIODevice*,
     * ma essendo che io derivo da QIODevice (perchè DBonIO
     * deriva da QIODevice) allora posso inizializzarli su me
     * stesso (ovvero sul file in cui scriverò) perchè punto a
     * una sottoclasse della classe base, usando il polimorfismo.
     */
{}

DBonXml::~DBonXml()
{}


void DBonXml::save(){

    qDebug()<<"DBonXml: **** CHIAMATO SALAVATAGGIO DB";

    if (QFile::open(QFile::WriteOnly) != true){
        dbState dst = read_only;
        setState(dst);
        return; //non posso scriverci, esco
    }

    write.setAutoFormatting( true );

    write.writeStartDocument();

    //USERS
    write.writeStartElement("Users");

    /*
     * va scritta la funzione save di user (dei suoi sottooggetti)
     * poi qui viene invocata solo se ovviamente l'user è valido!
     */

    DataMember::const_iterator it;

    for (it = cgetDb().cbegin(); it != cgetDb().cend(); ++it){

        if ( (*it)->isValid() == true ){
            //USER
            write.writeStartElement("User");
            //TYPE
            write.writeTextElement("Type",(*it)->cgetType());
            //END TYPE
            (*it)->save( write );

            write.writeEndElement();
            //END USER
        }
    }



    /*
     * Adesso verrà la chiamata a loadBack in caso qualche user
     * voglia salvare qualche operazione speciale.
     */

    //BACK
    write.writeStartElement("Back");

    for (it = cgetDb().cbegin(); it != cgetDb().cend(); ++it){

        if ((*it)->isValid() == true ){
            //OPT

            write.writeStartElement("Opt");

            (*it)->saveBack( write );

            write.writeEndElement();
            //END OPT
        }
    }

    write.writeEndElement();
    //END OPTIONAL


    write.writeEndElement();
    //END USERS


    QFile::close(); //chiudo il file

    qDebug()<<"DBonXml: **** SALVATAGGIO DB CONCLUSO";
}


void DBonXml::load(){

    /*
     * -Leggo che cosa sto "tirando su", in base a quello dichiaro
     * il tipo adatto (tipo "Basic"-> new MemberBasic) e gli sbatto
     * dentro i dati
     */

    if (QFile::open(QFile::ReadOnly) != true){
        setState(dbState::generic_error);
        return; //non posso leggere, esco
    }


    QXmlStreamReader::TokenType token;

    token = read.readNext();

    qDebug()<< "È elemento iniziale?";
    qDebug()<< (token == QXmlStreamReader::StartDocument);

    if (token != QXmlStreamReader::StartDocument){
        setState(dbState::bad_db);
        return; //file danneggiato?
    }

    read.readNextStartElement();

    qDebug()<< read.name();
    //USERS
    if (read.name() == "Users"){
        qDebug()<<"Entro nell'if dell Users";

        while( !read.atEnd() && !read.hasError() ){

            read.readNextStartElement();
            qDebug()<<"Nuova istruzione letta: "<<read.name();

            //USER
            if (read.name() == "User"){
                 qDebug()<<"Entro in User";

                 SmartMember nMember;

                 read.readNextStartElement();

                 QString type = read.readElementText();
                 qDebug()<<"Type"<<type;


                 //CREDENTIALS
                 read.readNextStartElement();

                 qDebug()<<read.name();

                 QString nick;
                 if (read.name() == "Credentials"){
                    qDebug()<<"Leggo le credenziali dell'utente";

                    read.readNextStartElement();
                    nick = read.readElementText();

                 }

                 read.skipCurrentElement();
                 //END CREDENTIALS

                 Credentials newCrd(nick);

                 if (type == "Basic"){

                   nMember = new MemberBasic(newCrd);
                 }
                 else if (type == "Business"){

                   nMember = new MemberBusiness(newCrd);
                 }
                 else if (type == "Executive"){

                   nMember = new MemberExecutive(newCrd);
                 }
                 else{
                 //nel caso trovo una tipologia che non so cosa sia

                   setState(dbState::bad_db);
                   return;
                 }

                 nMember->setAccountType( type );
                 //setto il suo tipo di user

                 qDebug()<<"Tipo account: "<<nMember->getType();

                 qDebug()<<"-------------------------------------";
                 qDebug()<<"Lascio che l'utente legga i suoi dati";
                 nMember->load( read ); //carica i suoi dati
                 qDebug()<<"L'utente ha letto i suoi dati";
                 qDebug()<<"-------------------------------------";


                 getDb().add( nMember ); //aggiungo il nuovo user

                 read.skipCurrentElement();
                 //END USER
            }

            if (read.name() == "Back"){

                qDebug()<<"Sono in back";

                DataMember::iterator itm;

                for (itm = getDb().begin();
                     itm != getDb().end();
                     ++itm) {

                    qDebug()<<"Sono nel for";

                    qDebug()<<"Utente: "<<(*itm)->cgetCredential().getCredential();

                    read.readNextStartElement();
                    qDebug()<<read.name();

                    //OPT
                    if (read.name() == "Opt"){

                        qDebug()<<"---------------------";
                        qDebug()<<"L'utente legge le opt";
                        (*itm)->loadBack( read );
                        qDebug()<<"L'utente ha letto le sue opt";
                        qDebug()<<"---------------------";
                    }

                    read.skipCurrentElement();
                    //END OPT
                }

                read.skipCurrentElement();
                //END BACK

                read.readNextStartElement();
                qDebug()<<read.name();
            }

        }
        read.skipCurrentElement();
        //END USERS
    }

    QFile::close();

}
