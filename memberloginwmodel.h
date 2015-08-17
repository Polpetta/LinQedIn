#ifndef MEMBERLOGINWMODEL_H
#define MEMBERLOGINWMODEL_H

#include "dbonxml.h"
#include "memberexecutive.h"
#include "smartmember.h"

//inclusione di controller di altre classi
#include "memberpanelwcontroller.h"

class MemberLoginWModel
{
public:
    MemberLoginWModel(Database* = new DBonXml("database"),
                      MemberPanelWController* = new MemberPanelWController);

    ~MemberLoginWModel();

    Database* getDb()const;

    SmartMember & getMember();
    const SmartMember & cgetMember()const;

    MemberPanelWController* getMemberPanelCtl()const;

    void setMember(const SmartMember &);

private:

    Database* db;
    SmartMember member;

    MemberPanelWController* memberPanel;
};

#endif // MEMBERLOGINWMODEL_H
