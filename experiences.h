#ifndef EXPERIENCES_H
#define EXPERIENCES_H

#include <QList>
#include <QVector>
#include "event.h"


class Experiences : private QList <Event>
{
public:
    Experiences();
    Experiences(const QVector<Event> &);

    void add (const Event &);
    void rm (const Event &);

    class iterator : public QList <Event>::iterator{

    public:
        iterator();
        iterator (const QList<Event>::iterator &);
    };

    Experiences::iterator begin();
    Experiences::iterator end();

    Event & operator[] (const Experiences::iterator &) const;


    class const_iterator : public QList <Event>::const_iterator{

    public:
        const_iterator();
        const_iterator (const QList <Event>::const_iterator &);
    };

    Experiences::const_iterator cbegin() const;
    Experiences::const_iterator cend() const;

    const Event & operator[] (const Experiences::const_iterator &) const;

    bool operator==(const Experiences &)const;
    bool operator!=(const Experiences &)const;

    int size()const;
};

#endif // EXPERIENCES_H
