#include "adminsearchmwmodel.h"

AdminSearchMWModel::AdminSearchMWModel()
{

}

const QVector<QString> & AdminSearchMWModel::cgetHobby()const{

    return hobbyBuffer;
}

const QVector<QString> & AdminSearchMWModel::cgetInterests() const{

    return interestsBuffer;
}

void AdminSearchMWModel::addH(const QString & nHobby){

    hobbyBuffer.push_back(nHobby);
}

void AdminSearchMWModel::addI(const QString & nInterests){

    interestsBuffer.push_back(nInterests);
}

void AdminSearchMWModel::wipeBuffers(){

    hobbyBuffer.clear();
    interestsBuffer.clear();
}
