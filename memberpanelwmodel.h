#ifndef MEMBERPANELWMODEL_H
#define MEMBERPANELWMODEL_H

#include "memberupdatewcontroller.h"
#include "memberfriendwcontroller.h"
#include "membersearchmwcontroller.h"

#include "smartmember.h"
#include "viewerpair.h"

class MemberPanelWModel
{
public:
    MemberPanelWModel(const SmartMember &,
                      const ViewerPair &);

    ~MemberPanelWModel();

    const SmartMember & cgetMember()const;
    SmartMember & getMember();

    void setMember(const SmartMember &);

    MemberUpdateWController* getMemberUpdateCtl()const;
    MemberFriendWController* getMemberFriendCtl()const;
    MemberSearchMWController* getMemberSearchCtl()const;


private:

    SmartMember info;
    MemberUpdateWController* updateCtl;
    MemberFriendWController* friendCtl;
    MemberSearchMWController* searchCtl;
};

#endif // MEMBERPANELWMODEL_H
