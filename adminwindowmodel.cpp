#include "adminwindowmodel.h"

AdminWindowModel::AdminWindowModel(Database* dbptr,
                                   const SmartAdmin & nAdmin,
                                   AdminAddMemberWC* nAddMemberCtl,
                                   AdminSearchMWController* nSearchMemberCtl)
    : db (dbptr),
      admin(nAdmin),
      addMember (nAddMemberCtl),
      searchMember (nSearchMemberCtl)
{

    db->load(); //carico il db
    admin = new Admin("Admin", db);
}

AdminWindowModel::~AdminWindowModel(){

    delete db;

    delete addMember;
    delete searchMember;
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
