#include "adminwindowview.h"



AdminWindowView::AdminWindowView( QWidget* parent )
    : QWidget (parent)
{

    QPushButton* addMember = new QPushButton ( tr ("Aggiungi Iscritto") );
    QPushButton* searchMember = new QPushButton ( tr ("Ricerca Iscritto") );
    QPushButton* rmMember = new QPushButton ( tr ("Rimuovi Iscritto") );
    QPushButton* changeMember = new QPushButton ( tr ( "Cambia tipo a Iscritto") );
    QPushButton* saveDb = new QPushButton ( tr ("Salva Db") );

    connect (addMember,
             SIGNAL (clicked()),
             this,
             SIGNAL (addMember()));
    connect (searchMember,
             SIGNAL (clicked()),
             this,
             SIGNAL (searchMember()));
    connect (rmMember,
             SIGNAL (clicked()),
             this,
             SIGNAL (rmMember()));
    connect (changeMember,
             SIGNAL (clicked()),
             this,
             SIGNAL (changeMember()));
    connect (saveDb,
             SIGNAL (clicked()),
             this,
             SIGNAL (saveDb()));


    QVBoxLayout* internalLy = new QVBoxLayout;
    QVBoxLayout* finalLy = new QVBoxLayout;

    internalLy->addWidget(addMember);
    internalLy->addWidget(searchMember);
    internalLy->addWidget(rmMember);
    internalLy->addWidget(changeMember);
    internalLy->addWidget(saveDb);

    QGroupBox* admActn = new QGroupBox ( tr ("Admin") );
    admActn->setLayout( internalLy );

    finalLy->addWidget( admActn );

    setLayout ( finalLy );

    setFixedSize( sizeHint() );




}

