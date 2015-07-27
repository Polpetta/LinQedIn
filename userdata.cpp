#include "userdata.h"

UserData::UserData()
{}

UserData::iterator::iterator() {}

UserData::iterator::iterator (const vector<SmartUtente>::iterator & it) : vector<SmartUtente>::iterator(it) {}

UserData::iterator UserData::begin(){

    return vector<SmartUtente>::begin();
}

UserData::iterator UserData::end(){

    return vector<SmartUtente>::end();
}

SmartUtente & UserData::operator [] (const UserData::iterator & it) const{

    return *it;
}


UserData::const_iterator::const_iterator(){}

UserData::const_iterator::const_iterator(const vector<SmartUtente>::const_iterator & it) : vector<SmartUtente>::const_iterator (it) {}

UserData::const_iterator UserData::cbegin() const{

    return vector<SmartUtente>::begin();
}

UserData::const_iterator UserData::cend() const{

    return vector<SmartUtente>::end();
}

const SmartUtente & UserData::operator [] (const UserData::const_iterator & it)const{

    return *it;
}

void UserData::add(const SmartUtente & newSU){

    vector<SmartUtente>::push_back(newSU);
}


void UserData::rm(const SmartUtente & target){

    vector<SmartUtente>::iterator it;

    for (it= vector<SmartUtente>::begin(); it != vector<SmartUtente>::end(); ++it){

        if (*it == target){

            SmartUtente last = vector<SmartUtente>::back();
            vector<SmartUtente>::pop_back();

            *it == last;
        }

    }
}
