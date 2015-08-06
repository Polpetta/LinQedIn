#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel()
    : admin (new AdminWindowController())
{}

MainWindowModel::~MainWindowModel(){

    delete admin;
}

AdminWindowController* MainWindowModel::getAdminController(){

    return admin;
}

