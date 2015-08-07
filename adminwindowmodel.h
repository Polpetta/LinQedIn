#ifndef ADMINWINDOWMODEL_H
#define ADMINWINDOWMODEL_H

#include "dbonxml.h"
#include "smartadmin.h"
#include "admin.h"

//controller di altre finestre
#include "adminaddmemberwc.h"

class AdminWindowModel
{
public:
    AdminWindowModel(Database * = new DBonXml ( "database" ),
                     const SmartAdmin & = SmartAdmin(),
                     AdminAddMemberWC* = new AdminAddMemberWC);

    ~AdminWindowModel();

    Database* getDb()const;
    SmartAdmin & getSmartAdmin();
    AdminAddMemberWC* getAddMemberCtl();

private:

    Database* db;
    SmartAdmin admin;

    AdminAddMemberWC* addMember;
};

#endif // ADMINWINDOWMODEL_H
