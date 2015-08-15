#include "memberloginwmodel.h"

MemberLoginWModel::MemberLoginWModel(Database* dbptr)
    : db (dbptr)
{

}

MemberLoginWModel::~MemberLoginWModel(){

    delete db;
}

Database* MemberLoginWModel::getDb()const{

    return db;
}
