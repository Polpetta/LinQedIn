#ifndef INTERESTS_H
#define INTERESTS_H

#include <QString>
#include <QVector>
#include <QList>


class Interests : private QList <QString>
{
public:
    Interests();
    Interests(const QVector<QString> &);

    void add(const QString &);
    void rm(const QString &);
    void purgeEquals();

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

    bool operator==(const Interests &)const;
    bool operator!=(const Interests &)const;

    bool contains(const QString &) const;

    int size()const;
};

#endif // INTERESTS_H
