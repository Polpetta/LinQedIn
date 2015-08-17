#include "memberloginwmodel.h"

MemberLoginWModel::MemberLoginWModel(Database* dbptr,
                                     MemberPanelWController* mbrPtr)
    : db (dbptr), member(nullptr), memberPanel (mbrPtr)
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
}

MemberPanelWController* MemberLoginWModel::getMemberPanelCtl()const{

    return memberPanel;
}
