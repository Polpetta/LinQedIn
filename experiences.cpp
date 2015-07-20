#include "experiences.h"

Experiences::Experiences()
{}

void Experiences::add(const Event & newEvent){

    list<Event>::push_back(newEvent);
}

void Experiences::rm(const Event & target){

    list<Event>::remove(target);
}

Experiences::iterator::iterator() {}

Experiences::iterator::iterator (const list<Event>::iterator & itr)
    : list<Event>::iterator(itr) {}

Experiences::iterator Experiences::begin(){

    return list<Event>::begin();
}

Experiences::iterator Experiences::end(){

    return list<Event>::end();
}

Event & Experiences::operator [] (const Experiences::iterator & it) const{

    return *it;
}



Experiences::const_iterator::const_iterator() {}

Experiences::const_iterator::const_iterator(const list<Event>::const_iterator & itr)
    : list <Event>::const_iterator (itr) {}

Experiences::const_iterator Experiences::cbegin() const{

    return list<Event>::begin();
}

Experiences::const_iterator Experiences::cend() const{

    return list<Event>::end();
}

const Event & Experiences::operator [] (const Experiences::const_iterator & it) const {

    return *it;
}
