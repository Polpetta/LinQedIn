#include "memberfriendwcontroller.h"

MemberFriendWController::MemberFriendWController(const SmartMember & member)
    : model (new MemberFriendWModel),
      view (new MemberFriendWView)
{

    connect (view,
             SIGNAL ( requestClose(QCloseEvent* )),
             this,
             SLOT (closeView(QCloseEvent* )));

    connect (view,
             SIGNAL ( execAddFriend(const QString &)),
             this,
             SLOT (addFriend(const QString &)));

    connect (view,
             SIGNAL ( execRmFriend(const QString &)),
             this,
             SLOT (rmFriend(const QString &)));

    listViewer* friendships = view->getFriendshipsList();

    const Friendships & itfFriend = member->cgetFriendships();

    Friendships::const_iterator itf;

    for (itf = itfFriend.cbegin(); itf != itfFriend.cend(); ++itf){

        friendships->addLabel(*itf);
    }

}

MemberFriendWController::~MemberFriendWController(){

    delete model;
    delete view;
}

void MemberFriendWController::showUI()const{

    view->show();
}

void MemberFriendWController::closeView(QCloseEvent *event) const{

    event->accept();

    emit resumePanel();
}

void MemberFriendWController::addFriend(const QString & newFriend) const{

    /*
     * Nota: questo passaggio può sembrare inutile ma in futuro in caso volessi
     * aggiungere ulteriori controlli non dovrei modificare nulla, ma solo
     * aggiungere codice a questa funzione (discorso analogo per rmFriend();
     */

    //rimbalzo segnale al pannello utente
    emit confirmAddFriend(newFriend);

    view->getFriendshipsList()->addLabel(newFriend);

    QMessageBox info(QMessageBox::Information,
                     tr ("Informazione su aggiunta amici"),
                     tr ("Verrà effettuata l'aggiunta della amizizia come"
                         " richiesto.<br><i>Nota</i> che se l'aggiunta non"
                         " risulterà essere valida,<br>l'amicizia non verrà"
                         " salvata."));

    info.exec();

}

void MemberFriendWController::rmFriend(const QString & target) const{

    //rimbalzo segnale
    emit confirmRmFriend(target);

    view->getFriendshipsList()->changeLabel(target, "<s>"+target+"</s>");
}
