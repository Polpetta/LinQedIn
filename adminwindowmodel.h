#ifndef ADMINWINDOWMODEL_H
#define ADMINWINDOWMODEL_H

#include "dbonxml.h"

class AdminWindowModel
{
public:
    AdminWindowModel(Database * = new DBonXml ( "database" ));

    ~AdminWindowModel();

    Database* getDb()const;

private:

    Database* db;
};

#endif // ADMINWINDOWMODEL_H
