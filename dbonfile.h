#ifndef DBONFILE_H
#define DBONFILE_H

#include "dbonio.h"
#include <QFile>
#include <QString>

class DBonFile : public DBonIO, public QFile
{
public:
    DBonFile(const QString & = QString());
    virtual ~DBonFile();

};

#endif // DBONFILE_H
