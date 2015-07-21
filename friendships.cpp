#include "friendships.h"

Friendships::Friendships()
{}

void Friendships::add(const int & newId){

    vector<int>::push_back(newId);
}

void Friendships::rm(const int & target){

    vector<int>::iterator it;

    for (it = vector<int>::begin(); it != vector<int>::end(); ++it){

        if (*it == target){

            int last = vector<int>::back();
            vector<int>::pop_back();

            *it = last;

        }

    }
}

Friendships::iterator::iterator() {}

Friendships::iterator::iterator (const vector<int>::iterator & itr)
    : vector<int>::iterator(itr) {}

Friendships::iterator Friendships::begin(){

    return vector<int>::begin();
}

Friendships::iterator Friendships::end(){

    return vector<int>::end();
}

int & Friendships::operator [] (const Friendships::iterator & it) const{

    return *it;
}



Friendships::const_iterator::const_iterator(){}

Friendships::const_iterator::const_iterator(const vector<int>::const_iterator & itr)
    : vector<int>::const_iterator(itr) {}

Friendships::const_iterator Friendships::cbegin() const{

    return vector<int>::begin();
}

Friendships::const_iterator Friendships::cend() const{

    return vector<int>::end();
}

const int & Friendships::operator [] (const Friendships::const_iterator & it)const{

    return *it;
}
