#ifndef ADMINWINDOWMODEL_H
#define ADMINWINDOWMODEL_H

#include "dbonxml.h"
#include "smartadmin.h"
#include "admin.h"
#include "datamember.h"

//controller di altre finestre
#include "adminaddmemberwc.h"
#include "adminsearchmwcontroller.h"
#include "adminrmmemberwcontroller.h"
#include "adminchangetypewcontroller.h"

class AdminWindowModel
{
public:
    AdminWindowModel(Database * = new DBonXml ( "database" ),
                     const SmartAdmin & = SmartAdmin(),
                     AdminAddMemberWC* = new AdminAddMemberWC,
                     AdminSearchMWController* = new AdminSearchMWController,
                     AdminRmMemberWController* = new AdminRmMemberWController,
                     AdminChangeTypeWController* = new AdminChangeTypeWController);

    ~AdminWindowModel();

    Database* getDb()const;
    SmartAdmin & getSmartAdmin();
    AdminAddMemberWC* getAddMemberCtl()const;
    AdminSearchMWController* getSearchMemberCtl()const;
    AdminRmMemberWController* getRmMemberCtl()const;
    AdminChangeTypeWController* getChangeMemberCtl()const;

private:

    Database* db;
    SmartAdmin admin;

    AdminAddMemberWC* addMember;
    AdminSearchMWController* searchMember;
    AdminRmMemberWController* rmMember;
    AdminChangeTypeWController* changeMember;
};

#endif // ADMINWINDOWMODEL_H
