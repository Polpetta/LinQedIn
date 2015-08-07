#include "adminaddmemberwm.h"

AdminAddMemberWM::AdminAddMemberWM(const SmartMember & newM)
    : newMember (newM)
{}

SmartMember & AdminAddMemberWM::getSmartMember(){

    return newMember;
}

const SmartMember & AdminAddMemberWM::cgetSmartMember()const{

    return newMember;
}

void AdminAddMemberWM::setSmartMember(const SmartMember & newSM){

    newMember = newSM;
}
