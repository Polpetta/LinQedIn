#include "adminwindowmodel.h"

AdminWindowModel::AdminWindowModel(Database* dbptr,
                                   const SmartAdmin & nAdmin,
                                   AdminAddMemberWC* nAddMemberCtl)
    : db (dbptr), admin(nAdmin), addMember (nAddMemberCtl)
{

    db->load(); //carico il db
}

AdminWindowModel::~AdminWindowModel(){

    delete db;

    delete addMember;
}

Database* AdminWindowModel::getDb()const{

    return db;
}

SmartAdmin & AdminWindowModel::getSmartAdmin(){

    return admin;
}

AdminAddMemberWC* AdminWindowModel::getAddMemberCtl(){

    return addMember;
}
