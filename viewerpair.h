#ifndef VIEWERPAIR_H
#define VIEWERPAIR_H

#include <QMap>
#include "msearchviewexecutive.h"
#include "mviewerviewexecutive.h"

//mi serve solo per tenere due puntatori nella QMap, nient'altro
struct viewCollection{

    MSearchView* sView;
    MViewerView* pView;

    viewCollection(MSearchView* search = nullptr,
                   MViewerView* profile = nullptr)
        : sView(search), pView(profile)
    {}

};

class ViewerPair : private QMap<QString,viewCollection*>
{
public:

    ViewerPair();

    void add(const QString &, viewCollection*);
    void rm (const QString &);

    class iterator : public QMap<QString,viewCollection*>::iterator{

    public:
        iterator();
        iterator(const QMap<QString,viewCollection*>::iterator &);
    };

    ViewerPair::iterator begin();
    ViewerPair::iterator end();

    viewCollection* operator[] (const QString &)const;

    class const_iterator : public QMap<QString,viewCollection*>::const_iterator{

    public:
        const_iterator();
        const_iterator (const QMap<QString,viewCollection*>::const_iterator &);
    };

    ViewerPair::const_iterator cbegin()const;
    ViewerPair::const_iterator cend()const;
};

#endif // VIEWERPAIR_H
