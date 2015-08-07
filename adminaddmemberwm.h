#ifndef ADMINADDMEMBERWM_H
#define ADMINADDMEMBERWM_H

#include "smartmember.h"
#include "memberexecutive.h"

class AdminAddMemberWM
{
public:
    AdminAddMemberWM( const SmartMember & = SmartMember() );

private:

    SmartMember newMember;
};

#endif // ADMINADDMEMBERWM_H
