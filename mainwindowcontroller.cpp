#include "mainwindowcontroller.h"

MainWindowController::~MainWindowController()
{
    delete model;
    delete view;

}

void MainWindowController::showUI(){

    view->show();
}

void MainWindowController::showAdmin()const{

    view->close();

    //ora carico il database lato amministrativo
    model->getAdminController()->loadDb();

    model->getAdminController()->showUI();

}

void MainWindowController::showLoginMember()const{

    view->close();
    model->getMemberLoginController()->showUI();
}

MainWindowController::MainWindowController(MainWindowModel* nModel,
                                           MainWindowView* nView)
    : model (nModel), view (nView)
{


    connect(view,
            SIGNAL ( adminViewCall() ),
            this,
            SLOT ( showAdmin() ));

    connect(view,
            SIGNAL ( memberLoginCall() ),
            this,
            SLOT ( showLoginMember() ));


    /*
     * Vengono create le varie connessioni
     */

}
