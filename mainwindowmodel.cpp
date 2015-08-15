#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel()
    : admin (new AdminWindowController()),
      memberLogin (new MemberLoginWController())
{

    /*
     * Non è meglio caricare tutta la parte amministrativa (o anche quella
     * dell'utente) solo quando effettivamente ce n'è bisogno?
     * Scritto com'è ora viene caricata tutta la zona amministrativa e
     * anche quella degli iscritti, ma alla fine se ne può scegliere solo
     * una, quindi l'altra rimarrà in memoria per niente!
     *
     * Non è ancora meglio spostare tutto il database sul MainWindowModel?
     */
}

MainWindowModel::~MainWindowModel(){

    delete admin;
    delete memberLogin;
}

AdminWindowController* MainWindowModel::getAdminController()const{

    return admin;
}

MemberLoginWController* MainWindowModel::getMemberLoginController()const{

    return memberLogin;
}
