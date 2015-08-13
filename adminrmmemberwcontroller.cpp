#include "adminrmmemberwcontroller.h"

void AdminRmMemberWController::closeView(QCloseEvent * event) const{

    event->accept();

    emit resumeAdmin();
}

AdminRmMemberWController::AdminRmMemberWController(AdminRmMemberWModel* nModel,
                                                   AdminRmMemberWView* nView)
    : model(nModel), view(nView)
{

    connect (view,
             SIGNAL (requestClose( QCloseEvent* ) ),
             this,
             SLOT (closeView( QCloseEvent* )));
    //da creare le varie connessioni

}

AdminRmMemberWController::~AdminRmMemberWController(){

    delete model;
    delete view;
}

void AdminRmMemberWController::showUI()const{

    view->show();
}
