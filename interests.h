#ifndef INTERESTS_H
#define INTERESTS_H

#include <QString>
#include <QList>


class Interests : private QList <QString>
{
public:
    Interests();

    void add(const QString &);
    void rm(const QString &);

    class iterator : public QList <QString>::iterator{

    public:
        iterator ();
        iterator (const QList<QString>::iterator &);
    };

    Interests::iterator begin();
    Interests::iterator end();

    QString & operator[] (const Interests::iterator &)const;

    class const_iterator : public QList <QString>::const_iterator{

    public:
        const_iterator ();
        const_iterator (const QList <QString>::const_iterator &);
    };

    Interests::const_iterator cbegin() const;
    Interests::const_iterator cend() const;

    const QString & operator[] (const Interests::const_iterator &) const;

};

#endif // INTERESTS_H
