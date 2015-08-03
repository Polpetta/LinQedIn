#ifndef HOBBY_H
#define HOBBY_H

#include <QString>
#include <QList>


class Hobby : private QList <QString>
{
public:
    Hobby();

    void add(const QString &);
    void rm(const QString &);

    class iterator : public QList <QString>::iterator{

    public:
        iterator ();
        iterator (const QList<QString>::iterator &);
    };

    Hobby::iterator begin() ;
    Hobby::iterator end() ;

    QString & operator[] (const Hobby::iterator &) const;

    class const_iterator : public QList <QString>::const_iterator{

    public:
        const_iterator ();
        const_iterator (const QList <QString>::const_iterator &);
    };

    Hobby::const_iterator cbegin() const;
    Hobby::const_iterator cend() const;

    const QString & operator[](const Hobby::const_iterator &) const;

};

#endif // HOBBY_H
