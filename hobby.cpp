#include "hobby.h"

Hobby::Hobby()
{}

void Hobby::add(const QString & newHobby){

    list<QString>::push_back(newHobby);
}

void Hobby::rm(const QString & target){

    list<QString>::remove(target);
}

Hobby::iterator::iterator() {}

Hobby::iterator::iterator(const list<QString>::iterator & itr)
    : list<QString>::iterator(itr) {}

Hobby::iterator Hobby::begin(){

    return list<QString>::begin();
}

Hobby::iterator Hobby::end(){

    return list<QString>::end();
}

QString & Hobby::operator [] (const Hobby::iterator & it) const{
    //DA RIGURARDARE
    return *it;
}


Hobby::const_iterator::const_iterator() {}

Hobby::const_iterator::const_iterator(const list<QString>::const_iterator & itr)
    : list<QString>::const_iterator(itr) {}

Hobby::const_iterator Hobby::begin() const{

    return list<QString>::begin();
}

Hobby::const_iterator Hobby::end() const{

    return list<QString>::end();
}

const QString& Hobby::operator [](const Hobby::const_iterator & it) const{
    return *it;
}
