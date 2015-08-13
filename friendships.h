#ifndef FRIENDSHIPS_H
#define FRIENDSHIPS_H

#include <vector>
#include <QString>
#include <QVector>

using std::vector;

class Friendships : private vector<QString>
{
public:
    Friendships();

    class iterator : public vector<QString>::iterator{

    public:
        iterator();
        iterator (const vector<QString>::iterator &);
    };

    Friendships::iterator begin();
    Friendships::iterator end();

    QString & operator[] (const Friendships::iterator &) const;

    class const_iterator : public vector <QString>::const_iterator{

    public:
        const_iterator();
        const_iterator (const vector<QString>::const_iterator &);
    };

    Friendships::const_iterator cbegin() const;
    Friendships::const_iterator cend() const;

    const QString & operator[] (const Friendships::const_iterator &) const;


    void add (const QString &);
    void rm (const QString &);

    QVector<QString> toVector()const;

};

#endif // FRIENDSHIPS_H
