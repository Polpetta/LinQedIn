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
    //qui ci andranno le finestre dell'admin e dell'user
    //che verranno chiamate dal controller
};

#endif // MAINWINDOWMODEL_H
