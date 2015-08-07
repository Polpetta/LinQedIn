#include "adminamwinterests.h"

AdminAMWInterests::AdminAMWInterests(QWidget* ptr)
    : QWizardPage (ptr)
{

    setTitle( tr ("Inserimento Interessi personali") );

    QLabel* note = new QLabel( tr( "Nota: questo passaggio è facoltativo") );

    QLabel* interests = new QLabel ( tr("Interesse") );
    QLineEdit* interestsEdit = new QLineEdit;

    QPushButton* insert = new QPushButton ( tr ("Aggiungi") );

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(note, 0, 0);

    layout->addWidget(interests, 1, 0);
    layout->addWidget(interestsEdit, 1, 1);
    layout->addWidget(insert, 2, 1);


    setLayout(layout);
}

AdminAMWInterests::~AdminAMWInterests(){


}

const QVector<QString> & AdminAMWInterests::cgetInterests()const{

    return interests;
}
