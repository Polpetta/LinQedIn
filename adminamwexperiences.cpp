#include "adminamwexperiences.h"

AdminAMWExperiences::AdminAMWExperiences(QWidget* parent)
    : QWizardPage (parent)
{


    setTitle ( tr("Inserimento Esperienze") );

    QLabel* note = new QLabel ( tr ("Nota: questo passaggio è facoltativo" ));

    QLabel* begin = new QLabel (tr("Data d'inizio (dd-mm-yyyy)"));
    QLabel* finish = new QLabel (tr("Data di fine (dd-mm-yyyy)"));
    QLabel* desc = new QLabel ( tr ("Breve descrizione"));
    QLabel* where = new QLabel ( tr("Luogo"));

    beginEdit = new QLineEdit;
    finishEdit = new QLineEdit;
    descEdit = new QLineEdit;
    whereEdit = new QLineEdit;

    QPushButton* insert = new QPushButton ( tr("Aggiungi"));

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(note, 0,0);

    layout->addWidget(begin, 1,0);
    layout->addWidget(beginEdit, 1, 1);

    layout->addWidget(finish, 2,0);
    layout->addWidget(finishEdit,2,1);

    layout->addWidget(desc, 3,0);
    layout->addWidget(descEdit, 3,1);

    layout->addWidget(where, 4,0);
    layout->addWidget(whereEdit,4,1);

    layout->addWidget(insert, 5, 1);

    setLayout(layout);

    connect (insert,
             SIGNAL (clicked()),
             this,
             SLOT (emitEvent()));

    connect(this,
            SIGNAL (newEvent(const Event &)),
            this,
            SLOT (addExperiences(const Event &)));
}

AdminAMWExperiences::~AdminAMWExperiences(){

    delete beginEdit;
    delete finishEdit;
    delete descEdit;
    delete whereEdit;
}

const QVector<Event> & AdminAMWExperiences::cgetExperiences()const{

    const QVector<Event>* aux = new QVector<Event> (experiences);

    return *aux;
}

void AdminAMWExperiences::clear(){

    experiences.clear();
}

void AdminAMWExperiences::emitEvent(){

    emit newEvent (Event(beginEdit->text(),
                         finishEdit->text(),
                         descEdit->text(),
                         whereEdit->text(),
                         "dd-MM-yyyy"));
}

void AdminAMWExperiences::addExperiences(const Event & newEvent){

    if (newEvent.isValid() == false){

        QMessageBox info (QMessageBox::Warning,
                          tr ( "Errore inserimento Evento"),
                          tr ("Alcuni parametri che hai inserito non sono"
                              " corretti."),
                          QMessageBox::Ok);

        info.exec();
    }else{

        experiences.push_back(newEvent);

        beginEdit->clear();
        finishEdit->clear();
        descEdit->clear();
        whereEdit->clear();

    }
}
