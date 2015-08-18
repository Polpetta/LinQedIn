#include "memberpanelwcontroller.h"

MemberPanelWController::MemberPanelWController(const SmartMember & member)
    : model(new MemberPanelWModel(member)),
      view(new MemberPanelWView)
{

    //ci andranno le varie connect
    connect(view,
            SIGNAL (requestClose( QCloseEvent* ) ),
            this,
            SLOT (closeSession( QCloseEvent* )) );

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

    connect (model->getMemberUpdateCtl(),
             SIGNAL (resumePanel()),
             this,
             SLOT (showUI()));

    connect (model->getMemberUpdateCtl(),
             SIGNAL (updateBioInfo(const Bio &)),
             this,
             SLOT (saveBio(const Bio &)));

    connect (model->getMemberUpdateCtl(),
             SIGNAL (insertHobby(const QString &)),
             this,
             SLOT (addHobby(const QString &)));

    connect (model->getMemberUpdateCtl(),
             SIGNAL (removeHobby(const QString &)),
             this,
             SLOT (rmHobby(const QString &)));

}

MemberPanelWController::~MemberPanelWController(){

}

void MemberPanelWController::showUI()const{

    view->show();
}

void MemberPanelWController::UpdateProfile()const{

    qDebug()<<"Sono in UpdateProfile";

    view->hide();

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

void MemberPanelWController::saveBio(const Bio & newBio) const{

    model->getMember()->getProfile().getPersonal().setBio(newBio);

    qDebug()<<"Aggiornamento nuove bio completato";
}

void MemberPanelWController::closeSession(QCloseEvent *event) const{

    //prima di chiudere tutto, accetto l'evento, salvo il db ed esco
    //per salvare il db devo andare in memberLogin

    event->accept();

    emit close();


}

void MemberPanelWController::addHobby(const QString & newHobby) const{

    model->getMember()->getProfile().getPersonal().getHobby().add(newHobby);
}

void MemberPanelWController::rmHobby(const QString & target) const{

    model->getMember()->getProfile().getPersonal().getHobby().rm(target);
}
