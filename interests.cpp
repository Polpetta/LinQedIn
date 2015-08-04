#include "interests.h"

Interests::Interests()
{}

void Interests::add(const QString & newInterests){

    QList<QString>::push_back(newInterests);
}

void Interests::rm(const QString & target){

    QList <QString>::removeAll(target);
}

Interests::iterator::iterator() {}

Interests::iterator::iterator(const QList<QString>::iterator & itr)
    : QList<QString>::iterator(itr) {}

Interests::iterator Interests::begin(){

    return QList<QString>::begin();
}

Interests::iterator Interests::end(){

    return QList<QString>::end();
}

QString & Interests::operator [] (const Interests::iterator & it) const{

    return *it;
}

Interests::const_iterator::const_iterator() {}

Interests::const_iterator::const_iterator(const QList::const_iterator & itr)
    :QList<QString>::const_iterator(itr) {}

Interests::const_iterator Interests::cbegin() const{

    return QList<QString>::begin();
}

Interests::const_iterator Interests::cend() const{

    return QList<QString>::end();
}

const QString & Interests::operator [] (const Interests::const_iterator & it) const{

    return *it;
}


bool Interests::operator==(const Interests & as)const{

    return QList<QString>::operator ==(as);
}

bool Interests::operator!=(const Interests & as)const{

    return QList<QString>::operator !=(as);
}
