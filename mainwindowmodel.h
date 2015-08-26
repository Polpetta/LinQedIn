#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include "adminwindowcontroller.h"
#include "memberloginwcontroller.h"
/*
 * Bisognerà includere i controller delle altre finestre
 */

class MainWindowModel
{
public:
    MainWindowModel();

    ~MainWindowModel();

    AdminWindowController* getAdminController();
    MemberLoginWController* getMemberLoginController();

private:

    AdminWindowController* admin;
    MemberLoginWController* memberLogin;
};

#endif // MAINWINDOWMODEL_H
