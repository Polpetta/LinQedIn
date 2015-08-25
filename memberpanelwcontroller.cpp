#include "memberpanelwcontroller.h"

MemberPanelWController::MemberPanelWController(const SmartMember & member,
                                               const ViewerPair & vp)
    : model(new MemberPanelWModel(member, vp)),
      view(new MemberPanelWView)
{
    view->setAccountType(member->cgetType());

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

    connect (model->getMemberUpdateCtl(),
             SIGNAL (insertInterests(const QString &)),
             this,
             SLOT (addInterests(const QString &)));

    connect (model->getMemberUpdateCtl(),
             SIGNAL (removeInterests(const QString &)),
             this,
             SLOT (rmInterests(const QString &)));

    connect (model->getMemberUpdateCtl(),
             SIGNAL (insertExperience(const Event &)),
             this,
             SLOT (addExperience(const Event &)));

    connect (model->getMemberUpdateCtl(),
             SIGNAL (removeExperience(const Event &)),
             this,
             SLOT (rmExperience(const Event &)));


    connect(model->getMemberFriendCtl(),
            SIGNAL (resumePanel()),
            this,
            SLOT (showUI()));

    connect (model->getMemberFriendCtl(),
             SIGNAL (confirmAddFriend(const QString &)),
             this,
             SLOT (addFriend(const QString &)));

    connect (model->getMemberFriendCtl(),
             SIGNAL (confirmRmFriend(const QString &)),
             this,
             SLOT (rmFriend(const QString &)));


    connect(model->getMemberSearchCtl(),
            SIGNAL (resumePanel()),
            this,
            SLOT (showUI()));

    connect(model->getMemberSearchCtl(),
            SIGNAL (querySearch(const Profile &)),
            this,
            SLOT (execSearch(const Profile &)));

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

    view->hide();

    model->getMemberFriendCtl()->showUI();
}

void MemberPanelWController::Search()const{

    qDebug()<<"Sono in Search";

    view->hide();

    model->getMemberSearchCtl()->showUI();
}

void MemberPanelWController::setMember(const SmartMember & newMember)const{

    model->setMember(newMember);
    view->setAccountType(newMember->cgetType());
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

void MemberPanelWController::addInterests(const QString &newInterest) const{

    model->getMember()->getProfile().getPersonal().getInterests().add(newInterest);
}

void MemberPanelWController::rmInterests(const QString & target) const{

    model->getMember()->getProfile().getPersonal().getInterests().rm(target);
}

void MemberPanelWController::addExperience(const Event &newEvent) const{

    model->getMember()->getProfile().getExperiences().add(newEvent);
}

void MemberPanelWController::rmExperience(const Event &target) const{

    model->getMember()->getProfile().getExperiences().rm(target);
}

void MemberPanelWController::addFriend(const QString &newFriend) const{

    model->getMember()->getFriendships().add(newFriend);
}

void MemberPanelWController::rmFriend(const QString &target) const{

    model->getMember()->getFriendships().rm(target);
}

void MemberPanelWController::execSearch(const Profile &toSearch) const{

    //eseguo la search con la chiamata polimorfa all'member

    model->getMemberSearchCtl()->setSearchResults(model->cgetMember()->search(toSearch));
}
