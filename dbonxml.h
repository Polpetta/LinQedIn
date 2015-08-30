#ifndef DBONXML_H
#define DBONXML_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttributes>

#include "dbonfile.h"
#include "user.h"
#include "memberexecutive.h"
#include "admin.h"

class DBonXml : public DBonFile
{
public:
    DBonXml(const QString &);
    virtual ~DBonXml();

    //ora posso definire come scriverò e come caricherò il db
    virtual void save();
    virtual void load();

private:

    QXmlStreamReader read;
    QXmlStreamWriter write;
};

#endif // DBONXML_H
