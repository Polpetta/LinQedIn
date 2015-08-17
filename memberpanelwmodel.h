#ifndef MEMBERPANELWMODEL_H
#define MEMBERPANELWMODEL_H

#include "memberupdatewcontroller.h"

#include "smartmember.h"

class MemberPanelWModel
{
public:
    MemberPanelWModel(const SmartMember & = SmartMember(nullptr));

    const SmartMember & cgetMember()const;
    SmartMember & getMember();

    void setMember(const SmartMember &);

    MemberUpdateWController* getMemberUpdateCtl()const;


private:

    SmartMember info;
    MemberUpdateWController* updateCtl;
};

#endif // MEMBERPANELWMODEL_H
