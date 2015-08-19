#include "memberpanelwview.h"

MemberPanelWView::MemberPanelWView(QWidget * ptr)
    : QWidget (ptr),
      typeAccount (new QLabel),
      layoutTot(new QVBoxLayout)
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

    delete typeAccount;
    delete layoutTot;
}

void MemberPanelWView::closeEvent(QCloseEvent * event){

    emit requestClose(event);
}

void MemberPanelWView::setAccountType(const QString & account){

    qDebug()<<"Nuovo tipo di account: "<<account;

    QString phrase = tr ("Tipo di account: ") + "<i>"+account+"</i>";

    typeAccount->setText(phrase);
    layoutTot->addWidget(typeAccount);
    setFixedSize( sizeHint() );
}
