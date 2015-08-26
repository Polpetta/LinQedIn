#ifndef DATAMEMBER_H
#define DATAMEMBER_H

#include <vector>
#include <QString>

#include "smartmember.h"
#include "data.h"

using std::vector;

class SmartMember;

class DataMember : public Data, private vector<SmartMember>
{
public:
    DataMember();
    virtual ~DataMember();

    class iterator : public vector<SmartMember>::iterator{

    public:
        iterator();
        iterator (const vector<SmartMember>::iterator &);
    };

    DataMember::iterator begin();
    DataMember::iterator end();

    SmartMember & operator[] (const DataMember::iterator &) const;

    class const_iterator : public vector<SmartMember>::const_iterator{

    public:
        const_iterator();
        const_iterator (const vector<SmartMember>::const_iterator &);
    };

    DataMember::const_iterator cbegin() const;
    DataMember::const_iterator cend() const;

    const SmartMember & operator[] (const DataMember::const_iterator &)const;

    void add (const SmartMember &);
    void rm (const SmartMember &);

    void clear();

    int size()const;



};

#endif // DATAMEMBER_H
