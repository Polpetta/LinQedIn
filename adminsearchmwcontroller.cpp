#include "adminsearchmwcontroller.h"

void AdminSearchMWController::closeView(QCloseEvent * event) const{

    event->accept(); //accetto l'evento della chiusura della finestra

    emit resumeAdmin();
}

AdminSearchMWController::AdminSearchMWController(AdminSearchMWModel* nModel,
                                                 AdminSearchMWView* nView)
    : model (nModel), view (nView)
{


    connect (view,
             SIGNAL (requestClose( QCloseEvent * )),
             this,
             SLOT (closeView( QCloseEvent* )));
    //ci andranno le varie connect
}

AdminSearchMWController::~AdminSearchMWController()
{

    delete model;
    delete view;
}

void AdminSearchMWController::showUI()const{

    view->show();
}
