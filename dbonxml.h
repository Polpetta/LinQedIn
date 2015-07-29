#ifndef DBONXML_H
#define DBONXML_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <dbonfile.h>

#include "user.h"
#include "friendships.h"
#include "member.h"

class DBonXml : public DBonFile
{
public:
    DBonXml(const QString & = QString());
    virtual ~DBonXml();

    //ora posso definire come scriverò e come caricherò il db
    virtual void save();
    virtual void load();

private:

    QXmlStreamReader read;
    QXmlStreamWriter write;
};

#endif // DBONXML_H
