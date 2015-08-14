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

    connect (view,
             SIGNAL (remove(const QString &) ),
             this,
             SLOT (rmMember(const QString &)));
    //da creare le varie connessioni

}

AdminRmMemberWController::~AdminRmMemberWController(){

    delete model;
    delete view;
}

void AdminRmMemberWController::showUI()const{

    view->show();
}

void AdminRmMemberWController::rmMember(const QString & nick)const{

    if (nick.size() == 0){

        QMessageBox info (QMessageBox::Information,
                          tr ("Cancellazione Membro"),
                          tr ("È necessario un nickname per<br>"
                              "eliminare un Membro") );

        info.exec();

        return; //non cancello nientem, non ha inserito niente
    }

    qDebug()<<"AdminRmController: ****CONFERMO RIMOZIONE UTENTE";

    emit rmMemberConfirm(nick);
}
