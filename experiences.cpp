#include "experiences.h"

Experiences::Experiences()
{}

Experiences::Experiences(const QVector<Event> & nExperiences)
    : QList<Event>(QList<Event>::fromVector(nExperiences))
{}

void Experiences::add(const Event & newEvent){

    QList<Event>::push_back(newEvent);
}

void Experiences::rm(const Event & target){

    QList<Event>::removeAll(target);
}

Experiences::iterator::iterator() {}

Experiences::iterator::iterator (const QList<Event>::iterator & itr)
    : QList<Event>::iterator(itr) {}

Experiences::iterator Experiences::begin(){

    return QList<Event>::begin();
}

Experiences::iterator Experiences::end(){

    return QList<Event>::end();
}

Event & Experiences::operator [] (const Experiences::iterator & it) const{

    return *it;
}



Experiences::const_iterator::const_iterator() {}

Experiences::const_iterator::const_iterator(const QList<Event>::const_iterator & itr)
    : QList <Event>::const_iterator (itr) {}

Experiences::const_iterator Experiences::cbegin() const{

    return QList<Event>::begin();
}

Experiences::const_iterator Experiences::cend() const{

    return QList<Event>::end();
}

const Event & Experiences::operator [] (const Experiences::const_iterator & it) const {

    return *it;
}


bool Experiences::operator ==(const Experiences & as)const{

    return QList<Event>::operator ==(as);
}

bool Experiences::operator !=(const Experiences & as)const{

    return QList<Event>::operator !=(as);
}


int Experiences::size()const{

    return QList<Event>::size();
}

QVector<Event> Experiences::toVector()const{

    return QList<Event>::toVector();
}
