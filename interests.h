#ifndef INTERESTS_H
#define INTERESTS_H

#include <list>
#include <QString>

using std::list;

class Interests : private list <QString>
{
public:
    Interests();

    void add(const QString &);
    void rm(const QString &);

    class iterator : public list <QString>::iterator{

    public:
        iterator ();
        iterator (const list<QString>::iterator &);
    };

    Interests::iterator begin();
    Interests::iterator end();

    QString & operator[] (const Interests::iterator &)const;

    class const_iterator : public list <QString>::const_iterator{

    public:
        const_iterator ();
        const_iterator (const list <QString>::const_iterator &);
    };

    Interests::const_iterator begin() const;
    Interests::const_iterator end() const;

    const QString & operator[] (const Interests::const_iterator &) const;

    /* Nota: da rivedere negli iteratori begin e end. Sembra che solo
     * quelli costanti vengano visti e overridino quelli non costanti
     */
};

#endif // INTERESTS_H
