#include "adminamwhobby.h"

AdminAMWHobby::AdminAMWHobby(QWidget * ptr)
    : QWizardPage(ptr)
{

    setTitle( tr ("Inserimento Hobby") );

    QLabel* note = new QLabel( tr( "Nota: questo passaggio è facoltativo") );

    QLabel* hobby = new QLabel ( tr("Hobby") );
    hobbyEdit = new QLineEdit;
    hobbyEdit->setClearButtonEnabled( true );

    QPushButton* insert = new QPushButton ( tr ("Aggiungi") );

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(note, 0,0);

    layout->addWidget(hobby, 1, 0);
    layout->addWidget(hobbyEdit, 1, 1);
    layout->addWidget(insert, 2, 1);

    setLayout(layout);

    connect (insert,
             SIGNAL (clicked()),
             this,
             SLOT (emitInsert()));

    connect (this,
             SIGNAL (newInsert(const QString &)),
             this,
             SLOT (addHobby(const QString &)));


}

AdminAMWHobby::~AdminAMWHobby(){

    delete hobbyEdit;
}

const QVector<QString> & AdminAMWHobby::cgetHobby()const{

    const QVector<QString>* aux = new QVector<QString>(hobby);

    return *aux;
}

void AdminAMWHobby::clear(){

    hobby.clear();
}

void AdminAMWHobby::emitInsert(){

    emit newInsert(hobbyEdit->text());
}

void AdminAMWHobby::addHobby(const QString & newHobby){

    hobby.push_back(newHobby);
    hobbyEdit->clear();
}
