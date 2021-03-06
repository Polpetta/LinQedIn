#include "memberloginwcontroller.h"

MemberLoginWController::MemberLoginWController(MemberLoginWModel* nModel,
                                               MemberLoginWView* nView)
    : model (nModel), view(nView)
{

    connect (view,
             SIGNAL (doLogin(const QString &)),
             this,
             SLOT (execLogin(const QString &)));
}


MemberLoginWController::~MemberLoginWController(){

    delete model;
    delete view;
}

void MemberLoginWController::showUI()const{

    view->show();
}

void MemberLoginWController::loadDb()const{

    model->getDb()->load();
}

void MemberLoginWController::execLogin(const QString & nickName) const{

    //controllo nel db se c'è quell'user.

    SmartMember userToLogin = model->getDb()->select(nickName);

    if (userToLogin == nullptr){

        QMessageBox info (QMessageBox::Warning,
                          tr ("Login non valido"),
                          tr ("Inserire delle credenziali corrette"));

        info.exec();

    }else{

        //qui devo costruire l'interfaccia per l'Iscritto
        model->setMember(userToLogin); //mi salvo l'utente loggato

        view->close();

        model->getMemberPanelCtl()->showUI();

        connect (model->getMemberPanelCtl(),
                 SIGNAL (close()),
                 this,
                 SLOT (exit()));
    }
}

void MemberLoginWController::exit()const{

    model->getDb()->save(); //salvo il db ed esco
}
