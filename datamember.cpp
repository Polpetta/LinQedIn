#include "datamember.h"
#include "member.h"

DataMember::DataMember()
{}

DataMember::~DataMember()
{}

DataMember::iterator::iterator(){}

DataMember::iterator::iterator (const vector<SmartMember>::iterator & it)
    : vector<SmartMember>::iterator(it)
{}

DataMember::iterator DataMember::begin(){

    return vector<SmartMember>::begin();
}

DataMember::iterator DataMember::end(){

    return vector<SmartMember>::end();
}

SmartMember & DataMember::operator [] (const DataMember::iterator & it) const{

    return *it;
}

DataMember::const_iterator::const_iterator(){}

DataMember::const_iterator::const_iterator(const vector<SmartMember>::const_iterator & it)
    : vector<SmartMember>::const_iterator (it)
{}

DataMember::const_iterator DataMember::cbegin() const{

    return vector<SmartMember>::begin();
}

DataMember::const_iterator DataMember::cend() const{

    return vector<SmartMember>::end();
}

const SmartMember & DataMember::operator[] (const DataMember::const_iterator & it) const {

    return *it;
}

void DataMember::add(const SmartMember & newSM){

    const QString & newNick = newSM->cgetCredential().getCredential();

    vector<SmartMember>::const_iterator it;

    bool match = false;

    for (it = vector<SmartMember>::begin(); it != vector<SmartMember>::end() && match == false; ++it){

        if (newNick == (*it)->cgetCredential().getCredential()){

            match = true;
        }
    }

    if (match == false){

        vector<SmartMember>::push_back(newSM);
    }
}

void DataMember::rm (const SmartMember & target){

    vector<SmartMember>::iterator it;

    for (it = vector<SmartMember>::begin(); it != vector<SmartMember>::end(); ++it){

        if (*it == target){

            (*it)->setAccountValid( false ); //disattivo l'account
        }
    }
}

void DataMember::clear(){

    vector<SmartMember>::clear();
}

int DataMember::size()const{

   return vector<SmartMember>::size();
}
