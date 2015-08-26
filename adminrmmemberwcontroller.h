#ifndef ADMINRMMEMBERWCONTROLLER_H
#define ADMINRMMEMBERWCONTROLLER_H


#include <QObject>
#include <QCloseEvent>
#include <QMessageBox>

#include "adminrmmemberwmodel.h"
#include "adminrmmemberwview.h"

class AdminRmMemberWController : public QObject
{
    Q_OBJECT

public:
    AdminRmMemberWController(AdminRmMemberWModel* = new AdminRmMemberWModel,
                             AdminRmMemberWView* = new AdminRmMemberWView);

    ~AdminRmMemberWController();

    void showUI()const;

signals:

    void resumeAdmin()const;
    void rmMemberConfirm(const QString &)const;

public slots:

    void closeView (QCloseEvent *)const;

    void rmMember(const QString &)const;

private:

    AdminRmMemberWModel* model;
    AdminRmMemberWView* view;
};

#endif // ADMINRMMEMBERWCONTROLLER_H
