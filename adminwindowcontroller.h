#ifndef ADMINWINDOWCONTROLLER_H
#define ADMINWINDOWCONTROLLER_H

#include <QObject>
#include <QMessageBox>

#include "admin.h"
#include "smartadmin.h"
#include "memberexecutive.h"

#include "adminwindowmodel.h"
#include "adminwindowview.h"

class AdminWindowController : public QObject
{

    Q_OBJECT

public slots:

    void execAddMember();
    void execSearchMember();
    void execRmMember();
    void execChangeMember();
    void execSaveDb();


public:
    AdminWindowController(AdminWindowModel* = new AdminWindowModel,
                          AdminWindowView* = new AdminWindowView,
                          SmartAdmin = SmartAdmin());

    virtual ~AdminWindowController();

    void showUI();

private:


    AdminWindowModel* model;
    AdminWindowView* view;


    SmartAdmin admin;
};

#endif // ADMINWINDOWCONTROLLER_H
