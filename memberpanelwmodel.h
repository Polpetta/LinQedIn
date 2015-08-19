#ifndef MEMBERPANELWMODEL_H
#define MEMBERPANELWMODEL_H

#include "memberupdatewcontroller.h"
#include "memberfriendwcontroller.h"

#include "smartmember.h"

class MemberPanelWModel
{
public:
    MemberPanelWModel(const SmartMember & = SmartMember(nullptr));

    ~MemberPanelWModel();

    const SmartMember & cgetMember()const;
    SmartMember & getMember();

    void setMember(const SmartMember &);

    MemberUpdateWController* getMemberUpdateCtl()const;
    MemberFriendWController* getMemberFriendCtl()const;


private:

    SmartMember info;
    MemberUpdateWController* updateCtl;
    MemberFriendWController* friendCtl;
};

#endif // MEMBERPANELWMODEL_H
