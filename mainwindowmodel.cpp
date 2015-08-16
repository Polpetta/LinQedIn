#include "mainwindowmodel.h"

MainWindowModel::MainWindowModel()
    : admin (nullptr),
      memberLogin (nullptr)
{

    /*
     * Non è meglio caricare tutta la parte amministrativa (o anche quella
     * dell'utente) solo quando effettivamente ce n'è bisogno?
     * Scritto com'è ora viene caricata tutta la zona amministrativa e
     * anche quella degli iscritti, ma alla fine se ne può scegliere solo
     * una, quindi l'altra rimarrà in memoria per niente!
     */
}

MainWindowModel::~MainWindowModel(){

    delete admin;
    delete memberLogin;
}

AdminWindowController* MainWindowModel::getAdminController(){

    if (admin == nullptr)
        admin = new AdminWindowController;

    return admin;
}

MemberLoginWController* MainWindowModel::getMemberLoginController(){

    if (memberLogin == nullptr)
        memberLogin = new MemberLoginWController;

    return memberLogin;
}
