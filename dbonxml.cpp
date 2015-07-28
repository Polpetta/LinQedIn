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

    if (QIODevice::open(QIODevice::WriteOnly) != true){
        dbState dst = read_only;
        setState(dst);
        return; //non posso scriverci, esco
    }

    write.setAutoFormatting( true );

    write.writeStartDocument();

    write.writeStartElement("Users");

    /*
     * va scritta la funzione save di user (dei suoi sottooggetti)
     * poi qui viene invocata solo se ovviamente l'user è valido!
     */
}


void DBonXml::load(){

    /*
     * per il momento vuota aspettando l'implementazione della
     * save()
     */
}
