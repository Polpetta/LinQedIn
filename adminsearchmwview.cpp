#include "adminsearchmwview.h"

AdminSearchMWView::AdminSearchMWView(QWidget* parent)
    : QWidget (parent)
{

    QLabel* info = new QLabel ( tr("<i>Tip:</i> eseguendo una ricerca"
                                   " vuota si otterrà tutto il Db") );
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

    nameEdit->setClearButtonEnabled( true );
    surnameEdit->setClearButtonEnabled( true );
    birthDayEdit->setClearButtonEnabled( true );

    hobbyEdit->setClearButtonEnabled( true );
    interestsEdit->setClearButtonEnabled( true );

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


    result = new TableSearch;


    QScrollArea* scrollResults = new QScrollArea;
    scrollResults->setWidget(result);

    scrollResults->setWidgetResizable( true );
    scrollResults->setFixedHeight(200);


    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(info);
    layoutTot->addWidget(note);
    layoutTot->addWidget(generic);
    layoutTot->addWidget(opt);
    layoutTot->addWidget(search);
    layoutTot->addWidget(scrollResults);

    setLayout(layoutTot);



    setFixedSize( sizeHint() );


    //connessioni dei bottoni
    connect (addHobby,
             SIGNAL (clicked()),
             this,
             SLOT (newFilterH()));

    connect (addInterests,
             SIGNAL (clicked()),
             this,
             SLOT (newFilterI()));

    connect (search,
             SIGNAL (clicked()),
             this,
             SLOT (commitSearch()));
}

AdminSearchMWView::~AdminSearchMWView()
{

    delete nameEdit;
    delete surnameEdit;
    delete birthDayEdit;

    delete hobbyEdit;
    delete interestsEdit;

    delete result;
    delete scrollResults;
}


void AdminSearchMWView::closeEvent(QCloseEvent * event){

    emit requestClose( event );
}

void AdminSearchMWView::newFilterH(){

    emit newHobbyFilter(hobbyEdit->text());
    hobbyEdit->clear();
}

void AdminSearchMWView::newFilterI(){

    emit newInterestsFilter(interestsEdit->text());
    interestsEdit->clear();
}

void AdminSearchMWView::commitSearch(){

    //result->clearUI(); //sta cosa fa crashare tutto


    emit searchConfirm (nameEdit->text(),
                        surnameEdit->text(),
                        birthDayEdit->text());


    //senza pulire i risultati è possibile fare un nuova ricerca aggiungendo
    //filtri
    /*nameEdit->clear();
    surnameEdit->clear();
    birthDayEdit->clear();*/
}

TableSearch* AdminSearchMWView::getTable()const{

    return result;
}

void AdminSearchMWView::showDetails(const QString & nick,
                                    const QString & name,
                                    const QString & surname,
                                    const QString & birth,
                                    const QString & phone,
                                    const QString & eMail,
                                    const QVector<QString> & hobby,
                                    const QVector<QString> & interests,
                                    const QVector<Event> & experience)const{

    //da implementare
    QMessageBox info(QMessageBox::NoIcon,
                     tr ("Informazioni su ") + nick,
                     tr ( "Prova"));

    info.exec();
}
