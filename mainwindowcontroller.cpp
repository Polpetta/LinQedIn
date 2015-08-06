#include "mainwindowcontroller.h"

MainWindowController::~MainWindowController()
{
    delete model;
    delete view;

}

void MainWindowController::showUI(){

    view->show();
}

void MainWindowController::showAdmin(){

    view->close();
    model->getAdminController()->showUI();

}

MainWindowController::MainWindowController(MainWindowModel* nModel,
                                           MainWindowView* nView)
    : model (nModel), view (nView)
{


    connect(view,
            SIGNAL ( adminViewCall() ),
            this,
            SLOT ( showAdmin() ));


    /*
     * Vengono create le varie connessioni
     */

}
