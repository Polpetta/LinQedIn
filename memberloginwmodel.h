#ifndef MEMBERLOGINWMODEL_H
#define MEMBERLOGINWMODEL_H

#include "dbonxml.h"
#include "memberexecutive.h"
#include "smartmember.h"

class MemberLoginWModel
{
public:
    MemberLoginWModel(Database* = new DBonXml("database"));

    ~MemberLoginWModel();

    Database* getDb()const;

    SmartMember & getMember();
    const SmartMember & cgetMember()const;

    void setMember(const SmartMember &);

private:

    Database* db;
    SmartMember member;
};

#endif // MEMBERLOGINWMODEL_H
