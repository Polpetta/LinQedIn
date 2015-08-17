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
}

MemberPanelWView::~MemberPanelWView(){


}
