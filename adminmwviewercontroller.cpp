#include "adminmwviewercontroller.h"

AdminMWViewerController::AdminMWViewerController(AdminMWViewerModel* nModel,
                                                 AdminMWViewerView* nView)
    : model (nModel), view (nView)
{

    //ci andranno le varie connect
}

AdminMWViewerController::~AdminMWViewerController(){

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
                                         const QVector<Event> & pExperience,
                                         const QVector<QString> & pFriendships)const{

    //semplicemente setto la view
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
