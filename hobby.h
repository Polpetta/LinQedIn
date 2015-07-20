#ifndef HOBBY_H
#define HOBBY_H

#include <list>
#include <QString>

using std::list;


class Hobby : private list <QString>
{
public:
    Hobby();

    void add(const QString &);
    void rm(const QString &);

    class iterator : public list <QString>::iterator{

    public:
        iterator ();
        iterator (const list<QString>::iterator &);
    };

    Hobby::iterator begin() ;
    Hobby::iterator end() ;

    QString & operator[] (const Hobby::iterator &) const;

    class const_iterator : public list <QString>::const_iterator{

    public:
        const_iterator ();
        const_iterator (const list <QString>::const_iterator &);
    };

    Hobby::const_iterator cbegin() const;
    Hobby::const_iterator cend() const;

    const QString & operator[](const Hobby::const_iterator &) const;

    /* Nota: da rivedere negli iteratori begin e end. Sembra che solo
     * quelli costanti vengano visti e overridino quelli non costanti
     */
};

#endif // HOBBY_H
