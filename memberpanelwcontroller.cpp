#include "memberpanelwcontroller.h"

MemberPanelWController::MemberPanelWController(const SmartMember & member)
    : model(new MemberPanelWModel(member)),
      view(new MemberPanelWView)
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

    //view->hide();

    model->getMemberUpdateCtl()->showUI();

}

void MemberPanelWController::ManageFriends()const{

    qDebug()<<"Sono in ManageFriends";
}

void MemberPanelWController::Search()const{

    qDebug()<<"Sono in Search";
}

void MemberPanelWController::setMember(const SmartMember & newMember)const{

    model->setMember(newMember);
}
