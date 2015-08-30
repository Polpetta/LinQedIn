#include "memberpanelwmodel.h"

MemberPanelWModel::MemberPanelWModel(const SmartMember & member,
                                     const ViewerPair & vp)
    : info (member),
      updateCtl(new MemberUpdateWController(member)),
      friendCtl(new MemberFriendWController(member)),
      searchCtl(new MemberSearchMWController(vp[member->cgetCredential().getCredential()]))
{}

MemberPanelWModel::~MemberPanelWModel(){

    delete updateCtl;
    delete friendCtl;
    delete searchCtl;

    //delete implicita di info
}

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

MemberFriendWController* MemberPanelWModel::getMemberFriendCtl()const{

    return friendCtl;
}

MemberSearchMWController* MemberPanelWModel::getMemberSearchCtl()const{

    return searchCtl;
}
