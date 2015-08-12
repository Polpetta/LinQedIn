#include "adminwindowcontroller.h"

void AdminWindowController::execAddMember()const{

    AdminAddMemberWC* newMemberCtl = model->getAddMemberCtl();

    view->hide();

    /*
     * Posso riesumare la view quando nel wizard premo sul bottone
     * "fine" o sul bottone "annulla"
     */

    newMemberCtl->showUI();
}

void AdminWindowController::SearchMember(const Profile & toSr) const{

    //DataMember* res = new DataMember;

    //*res = model->getDb()->select(target);

    /*
     * L'idea ora è quella di prendere il risultato e richiamare una funzione
     * del controller e passarglielo, poi il controller della sezione di
     * ricerca si arrangia lui a fare tutto il lavoro che deve fare.
     */

    model->getSearchMemberCtl()->setSearchResults(model->getSmartAdmin()->search(toSr));
}

void AdminWindowController::execSearchMember(){

    AdminSearchMWController* newSearchCtl = model->getSearchMemberCtl();

    view->hide();

    newSearchCtl->showUI();

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

    connect (model->getAddMemberCtl(),
             SIGNAL ( resumeAdmin(const SmartMember&) ),
             this,
             SLOT (addMember(const SmartMember &)));

    connect (model->getSearchMemberCtl(),
             SIGNAL (resumeAdmin() ),
             this,
             SLOT (showUI()));

    connect (model->getSearchMemberCtl(),
             SIGNAL (querySearch(const Profile &)),
             this,
             SLOT (SearchMember(const Profile &)));

    //creare le connect adatte
}

AdminWindowController::~AdminWindowController()
{

    delete model;
    delete view;
    //ci sarà la delete dell'admin, implicita
}


void AdminWindowController::showUI()const {

    view->show();
}

void AdminWindowController::addMember(const SmartMember & newMember)const{

    if (newMember.cgetPunt() != nullptr)
        model->getSmartAdmin()->addMember(newMember);

    showUI();
}
