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

    UserData::const_iterator it;

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

    write.writeEndElement();
    //END USERS

    /*
     * Adesso verrà la chiamata a loadBack in caso qualche user
     * voglia salvare qualche operazione speciale.
     */

    //BACK
    write.writeStartElement("Back");

    for (it = cgetDb().cbegin(); it != cgetDb().cend(); ++it){

        if ( (*it)->isValid() == true ){
            //OPT
            write.writeStartElement("Opt");

            (*it)->saveBack( write );

            write.writeEndElement();
            //END OPT
        }
    }

    write.writeEndElement();
    //END OPTIONAL

    QFile::close(); //chiudo il file
}


void DBonXml::load(){

    /*
     * per il momento vuota aspettando l'implementazione della
     * save()
     *
     * -Leggo che cosa sto "tirando su", in base a quello dichiaro
     * il tipo adatto (tipo "Basic"-> new MemberBasic) e gli sbatto
     * dentro i dati
     */

    if (QFile::open(QFile::ReadOnly) != true){
        dbState dst = generic_error;
        setState(dst);
        return; //non posso leggere, esco
    }

    read.readNext();

    if ( read.isStartElement() ){ //se è l'inizio del documento

        while ( read.atEnd() == false && isOk() == true){ //finchè ce n'è

            read.readNext();

            if (read.name() == "Users"){

                SmartUser uUser;

                read.readNext();

                if (read.name() == "User"){

                    QString type = read.attributes().value("Type").toString();

                    if (type == "Basic"){

                        uUser = new MemberBasic();
                    }
                    else if (type == "Business"){

                        uUser = new MemberBusiness();
                    }
                    else if (type == "Executive"){

                        uUser = new MemberExecutive();
                    }
                    else if (type == "Admin"){

                        uUser = new Admin();
                    }
                    else{
                        //nel caso trovo una tipologia che non so cosa sia

                        dbState error= bad_db;
                        setState(error);
                    }

                    uUser->setAccountType( type ); //setto il suo tipo di user
                    uUser->load( read ); //carica i suoi dati
                    getDb().add( uUser ); //aggiungo il nuovo user
                }
            }
        }
    }
}
