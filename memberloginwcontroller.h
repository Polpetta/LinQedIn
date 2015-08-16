#ifndef MEMBERLOGINWCONTROLLER_H
#define MEMBERLOGINWCONTROLLER_H

#include <QObject>

#include "memberloginwmodel.h"
#include "memberloginwview.h"

class MemberLoginWController : public QObject
{
    Q_OBJECT

public slots:

    void loadDb()const;

private slots:

    void execLogin(const QString &)const;

public:
    MemberLoginWController(MemberLoginWModel* = new MemberLoginWModel,
                           MemberLoginWView* = new MemberLoginWView);

    ~MemberLoginWController();

    void showUI()const;

private:

    MemberLoginWModel* model;
    MemberLoginWView* view;
};

#endif // MEMBERLOGINWCONTROLLER_H
