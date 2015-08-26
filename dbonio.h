#ifndef DBONIO_H
#define DBONIO_H

#include "database.h"
#include <QIODevice>

class DBonIO : public Database
{
public:
    DBonIO();
    virtual ~DBonIO();

    virtual void save() =0;
    virtual void load() =0;
};

#endif // DBONIO_H
