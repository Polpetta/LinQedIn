#include "adminwindowmodel.h"

AdminWindowModel::AdminWindowModel(Database* dbptr,
                                   const SmartAdmin & nAdmin,
                                   AdminAddMemberWC* nAddMemberCtl,
                                   AdminSearchMWController* nSearchMemberCtl,
                                   AdminRmMemberWController* nRmMemberCtl,
                                   AdminChangeTypeWController* nChangeMember)
    : db (dbptr),
      admin(nAdmin),
      addMember (nAddMemberCtl),
      searchMember (nSearchMemberCtl),
      rmMember (nRmMemberCtl),
      changeMember (nChangeMember)
{

    db->load(); //carico il db
    admin = new Admin("Admin", db);
}

AdminWindowModel::~AdminWindowModel(){

    delete db;

    delete addMember;
    delete searchMember;
    delete rmMember;
    delete changeMember;
}

Database* AdminWindowModel::getDb()const{

    return db;
}

SmartAdmin & AdminWindowModel::getSmartAdmin(){

    return admin;
}

AdminAddMemberWC* AdminWindowModel::getAddMemberCtl()const{

    return addMember;
}

AdminSearchMWController* AdminWindowModel::getSearchMemberCtl()const{

    return searchMember;
}

AdminRmMemberWController* AdminWindowModel::getRmMemberCtl()const{

    return rmMember;
}

AdminChangeTypeWController* AdminWindowModel::getChangeMemberCtl()const{

    return changeMember;
}
