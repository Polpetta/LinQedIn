#include "adminsearchmwview.h"

AdminSearchMWView::AdminSearchMWView(QWidget* parent)
    : QWidget (parent)
{

    QLabel* note = new QLabel ( tr("<i>Nota:</i> le date vanno espresse"
                                   " nel formato dd-mm-yyyy") );

    QLabel* name = new QLabel ( tr("Nome") );
    QLabel* surname = new QLabel ( tr("Cognome") );
    QLabel* birthDay = new QLabel ( tr("Data nascita") );

    QLabel* hobby = new QLabel ( tr("Hobby") );
    QLabel* interests = new QLabel ( tr ("Interessi ") );

    QPushButton* search = new QPushButton ( tr("Cerca") );
    QPushButton* addHobby = new QPushButton ( tr("Filtra") );
    QPushButton* addInterests = new QPushButton ( tr ("Filtra") );

    nameEdit = new QLineEdit;
    surnameEdit = new QLineEdit;
    birthDayEdit = new QLineEdit;

    hobbyEdit = new QLineEdit;
    interestsEdit = new QLineEdit;

    QGridLayout* layoutBio = new QGridLayout;

    layoutBio->addWidget(name, 0, 0);
    layoutBio->addWidget(nameEdit, 0, 1);

    layoutBio->addWidget(surname, 0, 2);
    layoutBio->addWidget(surnameEdit, 0, 3);

    layoutBio->addWidget(birthDay, 0 ,4);
    layoutBio->addWidget(birthDayEdit, 0, 5);

    QGroupBox* generic = new QGroupBox ( tr ("Ricerca Generica") );

    generic->setLayout(layoutBio);


    QGridLayout* layoutOpt = new QGridLayout;

    layoutOpt->addWidget(hobby, 0,0);
    layoutOpt->addWidget(hobbyEdit, 0,1);
    layoutOpt->addWidget(addHobby, 0, 2);

    layoutOpt->addWidget(interests, 1, 0);
    layoutOpt->addWidget(interestsEdit, 1, 1);
    layoutOpt->addWidget(addInterests, 1, 2);

    QGroupBox* opt = new QGroupBox ( tr("Filtri aggiuntivi") );

    opt->setLayout(layoutOpt);


    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(note);
    layoutTot->addWidget(generic);
    layoutTot->addWidget(opt);
    layoutTot->addWidget(search);

    setLayout(layoutTot);

    setFixedSize( sizeHint() );



}

AdminSearchMWView::~AdminSearchMWView()
{

    delete nameEdit;
    delete surnameEdit;
    delete birthDayEdit;

    delete hobbyEdit;
    delete interestsEdit;
}


void AdminSearchMWView::closeEvent(QCloseEvent * event){

    emit requestClose( event );
}
