#ifndef ADMINADDMEMBERWM_H
#define ADMINADDMEMBERWM_H

#include "smartmember.h"
#include "memberexecutive.h"

class AdminAddMemberWM
{
public:
    AdminAddMemberWM( const SmartMember & = SmartMember() );

    SmartMember & getSmartMember();
    const SmartMember & cgetSmartMember()const;

    void setSmartMember (const SmartMember &);

private:

    SmartMember newMember;
};

#endif // ADMINADDMEMBERWM_H
