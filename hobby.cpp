#include "hobby.h"

Hobby::Hobby()
{}

void Hobby::add(const QString & newHobby){

    QList<QString>::push_back(newHobby);
}

void Hobby::rm(const QString & target){

    QList<QString>::removeAll(target);
}

Hobby::iterator::iterator() {}

Hobby::iterator::iterator(const QList<QString>::iterator & itr)
    : QList<QString>::iterator(itr) {}

Hobby::iterator Hobby::begin(){

    return QList<QString>::begin();
}

Hobby::iterator Hobby::end(){

    return QList<QString>::end();
}

QString & Hobby::operator [] (const Hobby::iterator & it) const{

    return *it;
}


Hobby::const_iterator::const_iterator() {}

Hobby::const_iterator::const_iterator(const QList<QString>::const_iterator & itr)
    : QList<QString>::const_iterator(itr) {}

Hobby::const_iterator Hobby::cbegin() const{

    return QList<QString>::begin();
}

Hobby::const_iterator Hobby::cend() const{

    return QList<QString>::end();
}

const QString& Hobby::operator [](const Hobby::const_iterator & it) const{
    return *it;
}
