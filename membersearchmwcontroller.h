#ifndef MEMBERSEARCHMWCONTROLLER_H
#define MEMBERSEARCHMWCONTROLLER_H

#include <QObject>
#include <QCloseEvent>

#include "membersearchmwmodel.h"
#include "membersearchmwview.h"

class MemberSearchMWController : public QObject
{
    Q_OBJECT

signals:

    void resumePanel()const;

private slots:

    void closeView( QCloseEvent *)const;

public:
    MemberSearchMWController();

    ~MemberSearchMWController();

    void showUI()const;

private:

    MemberSearchMWModel* model;
    MemberSearchMWView* view;
};

#endif // MEMBERSEARCHMWCONTROLLER_H
