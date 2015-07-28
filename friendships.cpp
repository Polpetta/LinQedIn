#include "friendships.h"

Friendships::Friendships()
{}

Friendships::iterator::iterator() {}

Friendships::iterator::iterator (const vector<SmartUser>::iterator & itr)
    : vector<SmartUser>::iterator(itr) {}

Friendships::iterator Friendships::begin(){

    return vector<SmartUser>::begin();
}

Friendships::iterator Friendships::end(){

    return vector<SmartUser>::end();
}

SmartUser & Friendships::operator [] (const Friendships::iterator & it) const{

    return *it;
}



Friendships::const_iterator::const_iterator(){}

Friendships::const_iterator::const_iterator(const vector<SmartUser>::const_iterator & itr)
    : vector<SmartUser>::const_iterator(itr) {}

Friendships::const_iterator Friendships::cbegin() const{

    return vector<SmartUser>::begin();
}

Friendships::const_iterator Friendships::cend() const{

    return vector<SmartUser>::end();
}

const SmartUser & Friendships::operator [] (const Friendships::const_iterator & it)const{

    return *it;
}



void Friendships::add(const SmartUser & newId){

    vector<SmartUser>::push_back(newId);
}

void Friendships::rm(const SmartUser & target){

    vector<SmartUser>::iterator it;

    for (it = vector<SmartUser>::begin(); it != vector<SmartUser>::end(); ++it){

        if (*it == target){

            SmartUser last = vector<SmartUser>::back();
            vector<SmartUser>::pop_back();

            *it = last;

        }

    }
}

bool Friendships::isValid(const Friendships::const_iterator & it)const{

    //const User* tmp = (*it).cgetPunt();
    //bool res = tmp->isValid(); così va

    //bool res = (*it)->isValid; //così non va (?!) errore di tipo


    bool res = (*(*it)).isValid();

    return res;
}
