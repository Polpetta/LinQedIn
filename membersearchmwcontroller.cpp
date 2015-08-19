#include "membersearchmwcontroller.h"

MemberSearchMWController::MemberSearchMWController(const QString & type)
    : model(new MemberSearchMWModel),
      view (new MemberSearchMWView)
{

    if ( type == "Basic"){
        view->blockBio();
        view->blockHobby();
        view->blockInterests();

        view->setNote(tr("I membri di tipo <i>Basic</i> e"
                         " <i>Executive</i> possiedono<br> funzionalità"
                         " aggiuntive"));
    }else if ( type == "Business"){

        view->blockInterests();

        view->setNote(tr("I membri di tipo <i>Executive</i>"
                         " possiedono <br> funzionalità aggiuntive"));
    }

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
