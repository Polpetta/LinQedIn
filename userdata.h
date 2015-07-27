#ifndef USERDATA_H
#define USERDATA_H

#include<vector>
#include "user.h"
#include "smartuser.h"

using std::vector;

//altrimenti il compilatore va in loop.
class SmartUser;

class UserData : private vector<SmartUser>
{
public:
    UserData();

    class iterator : public vector<SmartUser>::iterator{

    public:
        iterator();
        iterator (const vector<SmartUser>::iterator &);
    };

    UserData::iterator begin();
    UserData::iterator end();

    SmartUser & operator[] (const UserData::iterator &) const;

    class const_iterator : public vector<SmartUser>::const_iterator{

    public:
        const_iterator();
        const_iterator(const vector<SmartUser>::const_iterator &);
    };

    UserData::const_iterator cbegin() const;
    UserData::const_iterator cend() const;

    const SmartUser & operator[] (const UserData::const_iterator &) const;

    void add (const SmartUser &);
    void rm (const SmartUser &);

};

#endif // USERDATA_H
