#ifndef MEMBERPANELWCONTROLLER_H
#define MEMBERPANELWCONTROLLER_H

#include <QObject>

#include <QDebug>

#include "memberpanelwmodel.h"
#include "memberpanelwview.h"

#include "smartmember.h"

class MemberPanelWController : public QObject
{
    Q_OBJECT

private slots:

    void UpdateProfile()const;
    void ManageFriends()const;
    void Search()const;

public slots:

    void showUI()const;

public:
    MemberPanelWController(const SmartMember &);

    ~MemberPanelWController();

    void setMember(const SmartMember &)const;

private:

    MemberPanelWModel* model;
    MemberPanelWView* view;
};

#endif // MEMBERPANELWCONTROLLER_H
