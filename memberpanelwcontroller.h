#ifndef MEMBERPANELWCONTROLLER_H
#define MEMBERPANELWCONTROLLER_H

#include <QObject>

#include "memberpanelwmodel.h"
#include "memberpanelwview.h"

class MemberPanelWController : public QObject
{
    Q_OBJECT

public:
    MemberPanelWController(MemberPanelWModel* = new MemberPanelWModel,
                           MemberPanelWView* = new MemberPanelWView);

    ~MemberPanelWController();

    void showUI()const;

private:

    MemberPanelWModel* model;
    MemberPanelWView* view;
};

#endif // MEMBERPANELWCONTROLLER_H
