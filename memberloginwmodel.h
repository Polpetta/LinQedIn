#ifndef MEMBERLOGINWMODEL_H
#define MEMBERLOGINWMODEL_H

#include "dbonxml.h"

class MemberLoginWModel
{
public:
    MemberLoginWModel(Database* = new DBonXml("database"));

    ~MemberLoginWModel();

    Database* getDb()const;

private:

    Database* db;
};

#endif // MEMBERLOGINWMODEL_H
