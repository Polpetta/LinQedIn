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

        if ( (*it)->isValid() == true )
            (*it)->save( write );
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
     */
}
