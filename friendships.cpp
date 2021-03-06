#include "friendships.h"

Friendships::Friendships()
{}

Friendships::iterator::iterator() {}

Friendships::iterator::iterator (const vector<QString>::iterator & itr)
    : vector<QString>::iterator(itr) {}

Friendships::iterator Friendships::begin(){

    return vector<QString>::begin();
}

Friendships::iterator Friendships::end(){

    return vector<QString>::end();
}

QString & Friendships::operator [] (const Friendships::iterator & it) const{

    return *it;
}



Friendships::const_iterator::const_iterator(){}

Friendships::const_iterator::const_iterator(const vector<QString>::const_iterator & itr)
    : vector<QString>::const_iterator(itr) {}

Friendships::const_iterator Friendships::cbegin() const{

    return vector<QString>::begin();
}

Friendships::const_iterator Friendships::cend() const{

    return vector<QString>::end();
}

const QString & Friendships::operator [] (const Friendships::const_iterator & it)const{

    return *it;
}



void Friendships::add(const QString & newId){

    vector<QString>::push_back(newId);
}

void Friendships::rm(const QString & target){

    vector<QString>::iterator it;

    for (it = vector<QString>::begin(); it != vector<QString>::end() &&
         vector<QString>::size() != 0; ++it){

        if (*it == target){

            QString last = vector<QString>::back();

            *it = last;

            vector<QString>::pop_back();

        }

    }
}

QVector<QString> Friendships::toVector()const{

    return QVector<QString>::fromStdVector(*this);
}
