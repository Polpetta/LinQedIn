#include "membermwviewercontroller.h"

MemberMWViewerController::MemberMWViewerController(MViewerView* nView)
    : model(new MemberMWViewerModel),
      view(nView)
{}

MemberMWViewerController::~MemberMWViewerController(){

    delete model;

    if (view != nullptr)
        delete view;
}

void MemberMWViewerController::resetView(){

    view->resetLayout();

}

void MemberMWViewerController::setProfile(const QString & pNick,
                                          const QString & pName,
                                          const QString & pSurname,
                                          const QString & pBirth,
                                          const QString & pPhone,
                                          const QString & pEmail,
                                          const QVector<QString> & pHobby,
                                          const QVector<QString> & pInterests,
                                          const QVector<QString> & pExperiences,
                                          const QVector<QString> & pFriendships)const{

    view->setProfile(pNick,
                     pName,
                     pSurname,
                     pBirth,
                     pPhone,
                     pEmail,
                     pFriendships,
                     pHobby,
                     pInterests,
                     pExperiences);

}

void MemberMWViewerController::showUI()const{

    view->show();
}
