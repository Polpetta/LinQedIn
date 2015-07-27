#ifndef USERDATA_H
#define USERDATA_H

#include<vector>
#include "smartutente.h"

using std::vector;

class UserData : private vector<SmartUtente>
{
public:
    UserData();

    class iterator : public vector<SmartUtente>::iterator{

    public:
        iterator();
        iterator (const vector<SmartUtente>::iterator &);
    };

    UserData::iterator begin();
    UserData::iterator end();

    SmartUtente & operator[] (const UserData::iterator &) const;

    class const_iterator : public vector<SmartUtente>::const_iterator{

    public:
        const_iterator();
        const_iterator(const vector<SmartUtente>::const_iterator &);
    };

    UserData::const_iterator cbegin() const;
    UserData::const_iterator cend() const;

    const SmartUtente & operator[] (const UserData::const_iterator &) const;

    void add (const SmartUtente &);
    void rm (const SmartUtente &);

};

#endif // USERDATA_H
