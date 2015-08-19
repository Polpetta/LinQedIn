#include "membersearchmwview.h"

MemberSearchMWView::MemberSearchMWView(QWidget* ptr)
    : QWidget (ptr),
      nameEdit(new QLineEdit),
      surnameEdit(new QLineEdit),
      birthDayEdit(new QLineEdit),
      search(new QPushButton ( tr ("Cerca") )),
      hobbyEdit(new QLineEdit),
      addHobby(new QPushButton ( tr("Filtra"))),
      interestsEdit(new QLineEdit),
      addInterests(new QPushButton ( tr("Filtra"))),
      result(new TableSearch),
      scrollResults(new QScrollArea)
{

    QLabel* note = new QLabel ( tr("<i>Nota:</i> le date vanno espresse nel"
                                   " formato dd-mm-yyyy") );

    QLabel* name = new QLabel ( tr ("Nome") );
    QLabel* surname = new QLabel ( tr("Cognome") );
    QLabel* birthDay = new QLabel ( tr("Data nascita") );

    QLabel* hobby = new QLabel ( tr("Hobby") );
    QLabel* interests = new QLabel ( tr("Interessi") );

    QPushButton* search = new QPushButton ( tr("Cerca") );
    QPushButton* addHobby = new QPushButton ( tr("Filtra") );
    QPushButton* addInterests = new QPushButton ( tr("Filtra") );

    nameEdit->setClearButtonEnabled( true );
    surnameEdit->setClearButtonEnabled( true );
    birthDayEdit->setClearButtonEnabled( true );

    hobbyEdit->setClearButtonEnabled( true );
    interestsEdit->setClearButtonEnabled( true );

    QGridLayout* layoutBio = new QGridLayout;

    layoutBio->addWidget(name, 0, 0);
    layoutBio->addWidget(nameEdit, 0, 1);

    layoutBio->addWidget(surname, 1, 0);
    layoutBio->addWidget(surnameEdit, 1, 1);

    layoutBio->addWidget(birthDay, 2, 0);
    layoutBio->addWidget(birthDayEdit, 2, 1);

    QGroupBox* generic = new QGroupBox ( tr("Ricerca Generica") );

    generic->setLayout(layoutBio);

    QGridLayout* layoutOpt = new QGridLayout;

    layoutOpt->addWidget(hobby, 0, 0);
    layoutOpt->addWidget(hobbyEdit, 0, 1);
    layoutOpt->addWidget(addHobby, 0, 2);

    layoutOpt->addWidget(interests, 1, 0);
    layoutOpt->addWidget(interestsEdit, 1, 1);
    layoutOpt->addWidget(addInterests, 1, 2);

    QGroupBox* opt = new QGroupBox ( tr("Filtri aggiuntivi") );

    opt->setLayout(layoutOpt);

    scrollResults->setWidget(result);

    scrollResults->setWidgetResizable( true );
    scrollResults->setFixedHeight(200);

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(note);
    layoutTot->addWidget(generic);
    layoutTot->addWidget(opt);
    layoutTot->addWidget(search);
    layoutTot->addWidget(scrollResults);

    setLayout(layoutTot);

    setFixedSize( sizeHint() );

    connect (addHobby,
             SIGNAL (clicked()),
             this,
             SLOT (addFilterH()));

    connect (addInterests,
             SIGNAL (clicked()),
             this,
             SLOT (addFilterI()));
}

MemberSearchMWView::~MemberSearchMWView(){

    delete nameEdit;
    delete surnameEdit;
    delete birthDayEdit;

    delete hobbyEdit;
    delete interestsEdit;

    delete result;
    delete scrollResults;

}

TableSearch* MemberSearchMWView::getTable()const{

    return result;
}

void MemberSearchMWView::closeEvent( QCloseEvent* event){

    emit requestClose(event);
}

void MemberSearchMWView::addFilterH()const{

    //bisognerà aggiungere il nuovo filtro SOLO se non è vuoto
}

void MemberSearchMWView::addFilterI()const{

    //idem
}
