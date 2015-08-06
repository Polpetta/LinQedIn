#include "adminwindowmodel.h"

AdminWindowModel::AdminWindowModel(Database* dbptr)
    : db (dbptr) //istanzio db
{

    db->load(); //carico il db
}

AdminWindowModel::~AdminWindowModel(){

    delete db;
}

Database* AdminWindowModel::getDb()const{

    return db;
}
