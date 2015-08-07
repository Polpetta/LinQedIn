#include "adminamwhobby.h"

AdminAMWHobby::AdminAMWHobby(QWidget * ptr)
    : QWizardPage(ptr)
{

    setTitle( tr ("Inserimento Hobby") );

    QLabel* note = new QLabel( tr( "Nota: questo passaggio è facoltativo") );

    QLabel* hobby = new QLabel ( tr("Hobby") );
    QLineEdit* hobbyEdit = new QLineEdit;

    QPushButton* insert = new QPushButton ( tr ("Aggiungi") );

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(note, 0,0);

    layout->addWidget(hobby, 1, 0);
    layout->addWidget(hobbyEdit, 1, 1);
    layout->addWidget(insert, 2, 1);

    setLayout(layout);
}

AdminAMWHobby::~AdminAMWHobby(){


}
