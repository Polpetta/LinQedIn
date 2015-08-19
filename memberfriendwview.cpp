#include "memberfriendwview.h"

MemberFriendWView::MemberFriendWView(QWidget* ptr)
    : QWidget (ptr),
      modifyFriend(new QLineEdit),
      friendships(new listViewer)
{

    QLabel* desc = new QLabel ( tr("In questa sezione è possibile modificare<br>"
                                   "le proprie amicizie. Nota che le amicizie<br>"
                                   "sono case sensitive.") );

    QPushButton* addFriend = new QPushButton ( tr("Aggiungi") );
    QPushButton* rmFriend = new QPushButton ( tr("Rimuovi") );

    QGridLayout* buttonL = new QGridLayout;

    buttonL->addWidget(addFriend, 0, 0);
    buttonL->addWidget(rmFriend, 0, 1);

    QScrollArea* scrollFriend = new QScrollArea;
    scrollFriend->setWidget( friendships );
    scrollFriend->setWidgetResizable( true );

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(desc);
    layoutTot->addWidget(scrollFriend);
    layoutTot->addWidget(modifyFriend);
    layoutTot->addLayout(buttonL);

    setLayout( layoutTot );

    setFixedSize( sizeHint() );

    connect(addFriend,
            SIGNAL (clicked()),
            this,
            SLOT (emitNewFriend()));

    connect(rmFriend,
            SIGNAL (clicked()),
            this,
            SLOT (emitRmFriend()));

}

MemberFriendWView::~MemberFriendWView()
{
    delete modifyFriend;
    delete friendships;
}

void MemberFriendWView::closeEvent (QCloseEvent* event){

    emit requestClose(event);
}

listViewer* MemberFriendWView::getFriendshipsList()const{

    return friendships;
}

void MemberFriendWView::emitNewFriend()const{

    //verranno eseguiti controlli se la stringa è stata modificata poi emit
    if (modifyFriend->isModified()){

        emit execAddFriend(modifyFriend->text());
        modifyFriend->clear();
    }else{

        QMessageBox info(QMessageBox::Information,
                         tr ("Aggiunta non valida"),
                         tr ("È necessario compilare il form") );

        info.exec();
    }
}

void MemberFriendWView::emitRmFriend()const{

    //come sopra
    if (modifyFriend->isModified()){

        emit execRmFriend(modifyFriend->text());
        modifyFriend->clear();
    }else{

        QMessageBox info(QMessageBox::Information,
                         tr ("Rimozione non valida"),
                         tr ("È necessario compilare il form"));

        info.exec();
    }
}
