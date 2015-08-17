#include "memberpanelwmodel.h"

MemberPanelWModel::MemberPanelWModel(const SmartMember & member)
    : info (member), updateCtl(new MemberUpdateWController(member))
{}

const SmartMember & MemberPanelWModel::cgetMember() const{

    return info;
}

SmartMember & MemberPanelWModel::getMember(){

    return info;
}

void MemberPanelWModel::setMember(const SmartMember & newMember){

    info = newMember;
}

MemberUpdateWController* MemberPanelWModel::getMemberUpdateCtl()const{

    return updateCtl;
}
