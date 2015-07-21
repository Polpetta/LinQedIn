#ifndef FRIENDSHIPS_H
#define FRIENDSHIPS_H

#include <vector>

using std::vector;


class Friendships : private vector<int>
{
public:
    Friendships();

    void add (const int &);
    void rm (const int &);

    class iterator : public vector<int>::iterator{

    public:
        iterator();
        iterator (const vector<int>::iterator &);
    };

    Friendships::iterator begin();
    Friendships::iterator end();

    int & operator[] (const Friendships::iterator &) const;

    class const_iterator : public vector <int>::const_iterator{

    public:
        const_iterator();
        const_iterator (const vector<int>::const_iterator &);
    };

    Friendships::const_iterator cbegin() const;
    Friendships::const_iterator cend() const;

    const int & operator[] (const Friendships::const_iterator &) const;

};

#endif // FRIENDSHIPS_H