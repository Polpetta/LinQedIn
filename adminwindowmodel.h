#ifndef ADMINWINDOWMODEL_H
#define ADMINWINDOWMODEL_H

#include "dbonxml.h"
#include "smartadmin.h"
#include "admin.h"
#include "datamember.h"

//controller di altre finestre
#include "adminaddmemberwc.h"
#include "adminsearchmwcontroller.h"

class AdminWindowModel
{
public:
    AdminWindowModel(Database * = new DBonXml ( "database" ),
                     const SmartAdmin & = SmartAdmin(),
                     AdminAddMemberWC* = new AdminAddMemberWC,
                     AdminSearchMWController* = new AdminSearchMWController);

    ~AdminWindowModel();

    Database* getDb()const;
    SmartAdmin & getSmartAdmin();
    AdminAddMemberWC* getAddMemberCtl()const;
    AdminSearchMWController* getSearchMemberCtl()const;

private:

    Database* db;
    SmartAdmin admin;

    AdminAddMemberWC* addMember;
    AdminSearchMWController* searchMember;
};

#endif // ADMINWINDOWMODEL_H
