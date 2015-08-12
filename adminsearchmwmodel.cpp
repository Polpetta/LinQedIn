#include "adminsearchmwmodel.h"

AdminSearchMWModel::AdminSearchMWModel()
    : searchResults (nullptr)
{

}

AdminSearchMWModel::~AdminSearchMWModel(){

    delete searchResults;
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

const DataMember* AdminSearchMWModel::getSearchResults()const{

    return searchResults;
}

void AdminSearchMWModel::wipeSearchResults(){

    if (searchResults != nullptr)
        delete searchResults;

    searchResults = nullptr;
}

void AdminSearchMWModel::setSearchResults(const DataMember & newResults){

    searchResults = &newResults;
}

const SmartMember & AdminSearchMWModel::getMemberByNick(const QString & nick) const{

    if (searchResults == nullptr){
        SmartMember* null = new SmartMember(nullptr);
        return *null;
    }

    DataMember::const_iterator it = searchResults->DataMember::cbegin();


    bool match = false;
    while (match == false && it != searchResults->cend()){

        const QString & snick = (*it)->cgetCredential().getCredential();

        if (nick == snick)
            match = true;
        else
            ++it;
    }

    return *it;
}
