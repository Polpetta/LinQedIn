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

    if (QFile::open(QFile::WriteOnly) != true){
        dbState dst = read_only;
        setState(dst);
        QFile::close();
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

    if (token != QXmlStreamReader::StartDocument){
        setState(dbState::bad_db);
        QFile::close();
        return; //file danneggiato?
    }

    read.readNextStartElement();

    //USERS
    if (read.name() == "Users"){

        while( !read.atEnd() && !read.hasError() ){

            read.readNextStartElement();

            //USER
            if (read.name() == "User"){

                 SmartMember nMember;

                 read.readNextStartElement();

                 QString type = read.readElementText();


                 //CREDENTIALS
                 read.readNextStartElement();

                 QString nick;
                 if (read.name() == "Credentials"){

                    read.readNextStartElement();
                    nick = read.readElementText();

                 }

                 read.skipCurrentElement();
                 //END CREDENTIALS

                 Credentials newCrd(nick);

                 viewCollection* collection = new viewCollection;

                 if (type == "Basic"){

                   nMember = new MemberBasic(newCrd);

                   collection->sView = new MSearchViewBasic;
                   collection->pView = new MViewerViewBasic;
                 }
                 else if (type == "Business"){

                   nMember = new MemberBusiness(newCrd);

                   collection->sView = new MSearchViewBusiness;
                   collection->pView = new MViewerViewBusiness;
                 }
                 else if (type == "Executive"){

                   nMember = new MemberExecutive(newCrd);

                   collection->sView = new MSearchViewExecutive;
                   collection->pView = new MViewerViewExecutive;
                 }
                 else{
                 //nel caso trovo una tipologia che non so cosa sia

                   setState(dbState::bad_db);
                   return;
                 }

                 getView().add(nick, collection);

                 nMember->setAccountType( type );
                 //setto il suo tipo di user

                 nMember->setDb(this);
                 //setto il database a questo oggetto

                 nMember->load( read ); //carica i suoi dati


                 getDb().add( nMember ); //aggiungo il nuovo user

                 read.skipCurrentElement();
                 //END USER
            }

            if (read.name() == "Back"){

                DataMember::iterator itm;

                for (itm = getDb().begin();
                     itm != getDb().end();
                     ++itm) {

                    read.readNextStartElement();

                    //OPT
                    if (read.name() == "Opt"){

                        (*itm)->loadBack( read );
                    }

                    read.skipCurrentElement();
                    //END OPT
                }

                read.skipCurrentElement();
                //END BACK

                read.readNextStartElement();
            }

        }
        read.skipCurrentElement();
        //END USERS
    }

    QFile::close();

}
