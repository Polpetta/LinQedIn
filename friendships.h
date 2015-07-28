#ifndef FRIENDSHIPS_H
#define FRIENDSHIPS_H

#include <vector>
#include "smartuser.h"

using std::vector;

/*
 * Meglio aggiungere un campo di numerazione su user o meglio
 * cambiare questa classe usando SmartUser?
 *
 */

class Friendships : private vector<SmartUser>
{
public:
    Friendships();

    class iterator : public vector<SmartUser>::iterator{

    public:
        iterator();
        iterator (const vector<SmartUser>::iterator &);
    };

    Friendships::iterator begin();
    Friendships::iterator end();

    SmartUser & operator[] (const Friendships::iterator &) const;

    class const_iterator : public vector <SmartUser>::const_iterator{

    public:
        const_iterator();
        const_iterator (const vector<SmartUser>::const_iterator &);
    };

    Friendships::const_iterator cbegin() const;
    Friendships::const_iterator cend() const;

    const SmartUser & operator[] (const Friendships::const_iterator &) const;


    void add (const SmartUser &);
    void rm (const SmartUser &);

    bool isValid(const Friendships::const_iterator & )const;
};

#endif // FRIENDSHIPS_H
