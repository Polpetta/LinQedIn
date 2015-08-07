#include "adminwindowcontroller.h"

void AdminWindowController::execAddMember(){

    AdminAddMemberWC* newMemberCtl = model->getAddMemberCtl();

    //view->hide();

    /*
     * Posso riesumare la view quando nel wizard premo sul bottone
     * "fine" o sul bottone "annulla"
     */

    newMemberCtl->showUI();
}

void AdminWindowController::execSearchMember(){


}

void AdminWindowController::execRmMember(){


}

void AdminWindowController::execChangeMember(){


}

void AdminWindowController::execSaveDb(){

    Database* db = model->getDb();

    db->save();

    QMessageBox info (QMessageBox::Information,
                      tr ( "Salva Db" ),
                      tr ("Salvataggio Database andato a buon fine"),
                      QMessageBox::Ok);

    info.exec();


}

AdminWindowController::AdminWindowController(AdminWindowModel* nModel,
                                             AdminWindowView* nView)
    :  model(nModel), view(nView)
{

    connect (view,
             SIGNAL ( addMember() ),
             this,
             SLOT ( execAddMember() ));

    connect (view,
             SIGNAL ( searchMember ()),
             this,
             SLOT ( execSearchMember()));

    connect (view,
             SIGNAL ( rmMember()),
             this,
             SLOT ( execRmMember() ));

    connect (view,
             SIGNAL ( changeMember() ),
             this,
             SLOT ( execChangeMember()));

    connect (view,
             SIGNAL ( saveDb()),
             this,
             SLOT ( execSaveDb()));

    //creare le connect adatte
}

AdminWindowController::~AdminWindowController()
{

    delete model;
    delete view;
    //ci sarà la delete dell'admin, implicita
}


void AdminWindowController::showUI(){

    view->show();
}
