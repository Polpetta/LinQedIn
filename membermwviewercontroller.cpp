#include "membermwviewercontroller.h"

MemberMWViewerController::MemberMWViewerController(MemberMWViewerModel* nModel)
    : model(nModel),
      view(nullptr)
{

}

MemberMWViewerController::~MemberMWViewerController(){

    delete model;

    if (view != nullptr)
        delete view;
}

void MemberMWViewerController::resetView(){

    if (view != nullptr)
        delete view;

    view = new MemberMWViewerView;

}

void MemberMWViewerController::setProfile(const QString & pNick,
                                          const QString & pName,
                                          const QString & pSurname,
                                          const QString & pBirth,
                                          const QString & pPhone,
                                          const QString & pEmail,
                                          const QVector<QString> & pFriendships)const{

    qDebug()<<"Sono in setProfile base: "<<view;

    if (view == nullptr)
        return;

    view->setProfile(pNick,
                     pName,
                     pSurname,
                     pBirth,
                     pPhone,
                     pEmail,
                     pFriendships); //settaggio view di base
}

void MemberMWViewerController::setProfile(const QString & pNick,
                                          const QString & pName,
                                          const QString & pSurname,
                                          const QString & pBirth,
                                          const QString & pPhone,
                                          const QString & pEmail,
                                          const QVector<QString> & pHobby,
                                          const QVector<QString> & pInterests,
                                          const QVector<QString> & pFriendships)const{

    qDebug()<<"Sono in setProfile medio";

    if (view == nullptr)
        return;

    setProfile(pNick,
               pName,
               pSurname,
               pBirth,
               pPhone,
               pEmail,
               pFriendships); //setto la base

    view->addHobby(pHobby);
    view->addInterests(pInterests);
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

    qDebug()<<"Sono in setProfile avanzato";

    if (view == nullptr)
        return;

    setProfile(pNick,
               pName,
               pSurname,
               pBirth,
               pPhone,
               pEmail,
               pHobby,
               pInterests,
               pFriendships);

    view->addExperiences(pExperiences);

}

void MemberMWViewerController::showUI()const{

    view->show();
}
