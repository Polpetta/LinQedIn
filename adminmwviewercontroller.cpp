#include "adminmwviewercontroller.h"

AdminMWViewerController::AdminMWViewerController(AdminMWViewerModel* nModel)
    : model (nModel), view (nullptr)
{}

AdminMWViewerController::~AdminMWViewerController(){

    if (view != nullptr)
        delete view;
    delete model;
}

void AdminMWViewerController::setProfile(const QString & pNick,
                                         const QString & pName,
                                         const QString & pSurname,
                                         const QString & pBirth,
                                         const QString & pPhone,
                                         const QString & pEMail,
                                         const QVector<QString> & pHobby,
                                         const QVector<QString> & pInterests,
                                         const QVector<QString> &pExperience,
                                         const QVector<QString> & pFriendships)const{

    if (view == nullptr)
        return;

    //setto la view
    view->setProfile(pNick,
                     pName,
                     pSurname,
                     pBirth,
                     pPhone,
                     pEMail,
                     pHobby,
                     pInterests,
                     pExperience,
                     pFriendships);

    view->show();
}

void AdminMWViewerController::resetView(){

    if (view != nullptr)
        delete view;

    view = new AdminMWViewerView;
}
