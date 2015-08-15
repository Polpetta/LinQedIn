#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel()
    : admin (new AdminWindowController()),
      memberLogin (new MemberLoginWController())
{}

MainWindowModel::~MainWindowModel(){

    delete admin;
    delete memberLogin;
}

AdminWindowController* MainWindowModel::getAdminController()const{

    return admin;
}

MemberLoginWController* MainWindowModel::getMemberLoginController()const{

    return memberLogin;
}
