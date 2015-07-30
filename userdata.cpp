#include "userdata.h"

UserData::UserData()
{}

UserData::iterator::iterator() {}

UserData::iterator::iterator (const vector<SmartUser>::iterator & it) : vector<SmartUser>::iterator(it) {}

UserData::iterator UserData::begin(){

    return vector<SmartUser>::begin();
}

UserData::iterator UserData::end(){

    return vector<SmartUser>::end();
}

SmartUser & UserData::operator [] (const UserData::iterator & it) const{

    return *it;
}


UserData::const_iterator::const_iterator(){}

UserData::const_iterator::const_iterator(const vector<SmartUser>::const_iterator & it) : vector<SmartUser>::const_iterator (it) {}

UserData::const_iterator UserData::cbegin() const{

    return vector<SmartUser>::begin();
}

UserData::const_iterator UserData::cend() const{

    return vector<SmartUser>::end();
}

const SmartUser & UserData::operator [] (const UserData::const_iterator & it)const{

    return *it;
}

void UserData::add(const SmartUser & newSU){

    const QString & newNick = newSU->cgetCredential().getCredential();

    vector<SmartUser>::const_iterator it;
    bool match = false;

    for (it = vector<SmartUser>::begin(); it != vector<SmartUser>::end() && match != false; ++it){

        if (newNick == (*it)->cgetCredential().getCredential()){
            match = true;
        }
    }

    if (match == false){

        vector<SmartUser>::push_back(newSU);
    }
}


void UserData::rm(const SmartUser & target){

    vector<SmartUser>::iterator it;

    for (it= vector<SmartUser>::begin(); it != vector<SmartUser>::end(); ++it){

        if (*it == target){

            SmartUser last = vector<SmartUser>::back();
            vector<SmartUser>::pop_back();

            *it == last;
        }

    }
}
