#include "adminamwinterests.h"

AdminAMWInterests::AdminAMWInterests(QWidget* ptr)
    : QWizardPage (ptr)
{

    setTitle( tr ("Inserimento Interessi personali") );

    QLabel* note = new QLabel( tr( "Nota: questo passaggio è facoltativo") );

    QLabel* interests = new QLabel ( tr("Interesse") );
    interestsEdit = new QLineEdit;
    interestsEdit->setClearButtonEnabled( true );

    QPushButton* insert = new QPushButton ( tr ("Aggiungi") );

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(note, 0, 0);

    layout->addWidget(interests, 1, 0);
    layout->addWidget(interestsEdit, 1, 1);
    layout->addWidget(insert, 2, 1);


    setLayout(layout);

    connect (insert,
             SIGNAL (clicked()),
             this,
             SLOT (emitInsert()));

    connect (this,
             SIGNAL (newInsert(const QString &)),
             this,
             SLOT (addInterests (const QString &)));
}

AdminAMWInterests::~AdminAMWInterests(){

    delete interestsEdit;
}

const QVector<QString> & AdminAMWInterests::cgetInterests()const{

    const QVector<QString>* aux = new QVector<QString>(interests);

    return *aux;
}

void AdminAMWInterests::clear(){

    interests.clear();
}

void AdminAMWInterests::emitInsert(){

    if (interestsEdit->isModified() && interestsEdit->text() != "")
        emit newInsert(interestsEdit->text());
    else{

        QMessageBox info(QMessageBox::Warning,
                         tr("Inserimento vuoto"),
                         tr ("Non è possibile inserire un interesse vuoto"));

        info.exec();
    }
}

void AdminAMWInterests::addInterests(const QString & newInterest){

    interests.push_back(newInterest);
    interestsEdit->clear();
}
