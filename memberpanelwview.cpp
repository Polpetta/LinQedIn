#include "memberpanelwview.h"

MemberPanelWView::MemberPanelWView(QWidget * ptr)
    : QWidget (ptr)
{

    /*
     * Funzionalità richieste:
     * -Aggiornamento proprio profilo
     * -Inserimento di un nuovo contatto nella propria rete
     * -Rimozione di un contatto dalla propria rete
     * -Funzionalità di ricerca sul Db
     */

    QPushButton* updateProfile = new QPushButton ( tr ("Aggiornamento profilo") );

    QPushButton* manageFriends = new QPushButton ( tr ("Modifica Amicizie") );

    QPushButton* search = new QPushButton ( tr ("Ricerca") );

    QVBoxLayout* layoutGroup = new QVBoxLayout;

    layoutGroup->addWidget(updateProfile);
    layoutGroup->addWidget(manageFriends);
    layoutGroup->addWidget(search);

    QGroupBox* group = new QGroupBox ( tr ("Azioni Iscritto") );

    group->setLayout(layoutGroup);

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(group);

    setLayout(layoutTot);

    setFixedSize( sizeHint () );

    connect (updateProfile,
             SIGNAL (clicked()),
             this,
             SIGNAL (execUpdateProfile()));

    connect (manageFriends,
             SIGNAL (clicked()),
             this,
             SIGNAL (execManageFriends()));

    connect (search,
             SIGNAL (clicked()),
             this,
             SIGNAL (execSearch()));
}

MemberPanelWView::~MemberPanelWView(){


}

void MemberPanelWView::closeEvent(QCloseEvent * event){

    emit requestClose(event);
}
