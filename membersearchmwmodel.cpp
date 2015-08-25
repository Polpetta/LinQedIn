#include "membersearchmwmodel.h"

MemberSearchMWModel::MemberSearchMWModel()
    : lastResults(nullptr),
      typeSearch(),
      profileViewer(new MemberMWViewerController)
{

}

MemberSearchMWModel::~MemberSearchMWModel(){

    if (lastResults != nullptr)
        delete lastResults;

    delete profileViewer;
}

void MemberSearchMWModel::setSearchResults(const DataMember &result){

    if (lastResults != nullptr)
        delete lastResults;

    lastResults = &result;
}

const DataMember* MemberSearchMWModel::getSearchResults()const{

    return lastResults;
}

void MemberSearchMWModel::wipeSearchResults(){

    if (lastResults != nullptr )
        delete lastResults;

    lastResults = nullptr;
}

const SmartMember & MemberSearchMWModel::getMemberByNick(const QString & nick) const{

    if (lastResults == nullptr ){
        SmartMember* null = new SmartMember(nullptr);
        return *null;
    }

    DataMember::const_iterator it = lastResults->DataMember::cbegin();

    bool match = false;
    while (match == false && it != lastResults->cend()){

        const QString & snick = (*it)->cgetCredential().getCredential();

        if (nick == snick)
            match = true;
        else
            ++it;
    }

    return *it;
}

void MemberSearchMWModel::addH(const QString &newHobby){

    hobbyBuffer.push_back(newHobby);
}

void MemberSearchMWModel::addI(const QString &newInterests){

    interestsBuffer.push_back(newInterests);
}

const QVector<QString> & MemberSearchMWModel::cgetHobby()const{

    return hobbyBuffer;
}

const QVector<QString> & MemberSearchMWModel::cgetInterests()const{

    return interestsBuffer;
}

const QString & MemberSearchMWModel::cgetType()const{

    return typeSearch;
}

void MemberSearchMWModel::setType(const QString & newType){

    typeSearch = newType;
}

void MemberSearchMWModel::wipeBuffers(){

    hobbyBuffer.clear();
    interestsBuffer.clear();
}

MemberMWViewerController* MemberSearchMWModel::getProfileViewer()const{

    return profileViewer;
}
