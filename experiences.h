#ifndef EXPERIENCES_H
#define EXPERIENCES_H

#include <list>
#include "event.h"

using std::list;

class Experiences : private list <Event>
{
public:
    Experiences();

    void add (const Event &);
    void rm (const Event &);

    class iterator : public list <Event>::iterator{

    public:
        iterator();
        iterator (const list<Event>::iterator &);
    };

    Experiences::iterator begin();
    Experiences::iterator end();

    Event & operator[] (const Experiences::iterator &) const;


    class const_iterator : public list <Event>::const_iterator{

    public:
        const_iterator();
        const_iterator (const list <Event>::const_iterator &);
    };

    Experiences::const_iterator cbegin() const;
    Experiences::const_iterator cend() const;

    const Event & operator[] (const Experiences::const_iterator &) const;

};

#endif // EXPERIENCES_H
