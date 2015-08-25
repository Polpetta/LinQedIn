#ifndef VIEWERPAIR_H
#define VIEWERPAIR_H

#include <QMap>
#include "msearchviewexecutive.h"

class ViewerPair : private QMap<QString,MSearchView*>
{
public:
    ViewerPair();

    void add(const QString &, MSearchView*);
    void rm (const QString &);

    class iterator : public QMap<QString,MSearchView*>::iterator{

    public:
        iterator();
        iterator(const QMap<QString,MSearchView*>::iterator &);
    };

    ViewerPair::iterator begin();
    ViewerPair::iterator end();

    MSearchView* operator[] (const QString &)const;

    class const_iterator : public QMap<QString,MSearchView*>::const_iterator{

    public:
        const_iterator();
        const_iterator (const QMap<QString,MSearchView*>::const_iterator &);
    };

    ViewerPair::const_iterator cbegin()const;
    ViewerPair::const_iterator cend()const;

    //const MSearchView* operator[](const QString &)const;
};

#endif // VIEWERPAIR_H
