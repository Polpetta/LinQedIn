#include "memberloginwmodel.h"

MemberLoginWModel::MemberLoginWModel(Database* dbptr)
    : db (dbptr), member(nullptr), memberPanel (nullptr)
{

}

MemberLoginWModel::~MemberLoginWModel(){

    delete db;
}

Database* MemberLoginWModel::getDb()const{

    return db;
}

SmartMember & MemberLoginWModel::getMember(){

    return member;
}

const SmartMember & MemberLoginWModel::cgetMember()const{

    return member;
}

void MemberLoginWModel::setMember(const SmartMember & newMember){

    member = newMember;

    if (memberPanel == nullptr)
        memberPanel = new MemberPanelWController(member);
    else
        memberPanel->setMember(member);
}

MemberPanelWController* MemberLoginWModel::getMemberPanelCtl()const{

    return memberPanel;
}
