#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include "adminwindowcontroller.h"
/*
 * Bisognerà includere i controller delle altre finestre
 */

class MainWindowModel
{
public:
    MainWindowModel();

    ~MainWindowModel();

    AdminWindowController* getAdminController();

private:

    AdminWindowController* admin;
    //qui ci andranno le finestre dell'admin e dell'user
    //che verranno chiamate dal controller
};

#endif // MAINWINDOWMODEL_H
