#include "interests.h"

Interests::Interests()
{}

void Interests::add(const QString & newInterests){

    list<QString>::push_back(newInterests);
}

void Interests::rm(const QString & target){

    list <QString>::remove(target);
}

Interests::iterator::iterator() {}

Interests::iterator::iterator(const list<QString>::iterator & itr)
    : list<QString>::iterator(itr) {}

Interests::iterator Interests::begin(){

    return list<QString>::begin();
}

Interests::iterator Interests::end(){

    return list<QString>::end();
}

QString & Interests::operator [] (const Interests::iterator & it) const{
    //DA RIGUARDARE
    return *it;
}

Interests::const_iterator::const_iterator() {}

Interests::const_iterator::const_iterator(const list::const_iterator & itr)
    :list<QString>::const_iterator(itr) {}

Interests::const_iterator Interests::begin() const{

    return list<QString>::begin();
}

Interests::const_iterator Interests::end() const{

    return list<QString>::end();
}

const QString & Interests::operator [] (const Interests::const_iterator & it) const{

    return *it;
}
