#include "membersearchmwcontroller.h"

MemberSearchMWController::MemberSearchMWController()
    : model(new MemberSearchMWModel),
      view (new MemberSearchMWView)
{

    connect (view,
             SIGNAL (requestClose( QCloseEvent *)),
             this,
             SLOT (closeView( QCloseEvent* )));
}

MemberSearchMWController::~MemberSearchMWController(){

    delete model;
    delete view;
}


void MemberSearchMWController::showUI()const{

    view->show();
}

void MemberSearchMWController::closeView(QCloseEvent *event) const{

    event->accept();

    emit resumePanel();
}
