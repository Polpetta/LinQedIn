#include "memberpanelwcontroller.h"

MemberPanelWController::MemberPanelWController(MemberPanelWModel* nModel,
                                               MemberPanelWView* nView)
    : model(nModel), view(nView)
{

    connect(view,
            SIGNAL (execUpdateProfile()),
            this,
            SLOT (UpdateProfile()));

    connect (view,
             SIGNAL (execManageFriends()),
             this,
             SLOT (ManageFriends()));

    connect (view,
             SIGNAL (execSearch()),
             this,
             SLOT (Search()));
    //ci andranno le varie connect
}

MemberPanelWController::~MemberPanelWController(){


}

void MemberPanelWController::showUI()const{

    view->show();
}

void MemberPanelWController::UpdateProfile()const{

    qDebug()<<"Sono in UpdateProfile";
}

void MemberPanelWController::ManageFriends()const{

    qDebug()<<"Sono in ManageFriends";
}

void MemberPanelWController::Search()const{

    qDebug()<<"Sono in Search";
}
