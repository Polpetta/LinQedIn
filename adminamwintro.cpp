#include "adminamwintro.h"

AdminAMWIntro::AdminAMWIntro(QWidget * ptr)
    : QWizardPage(ptr)
{

    setTitle( tr ("Aggiunta nuovo Iscritto") );

    QLabel* intro = new QLabel( tr("La procedura guidata vi permetterà di "
                                   "aggiungere un nuovo Iscritto.") );

    QLineEdit* userType = new QLineEdit;

    QLabel* note = new QLabel( tr ("I member per il momento possono essere: <i>Basic</i>, <i>Business</i>, <i>Executive</i>"));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(intro);
    layout->addWidget(userType);
    layout->addWidget(note);

    registerField("userType*", userType);

    setLayout(layout);
}

AdminAMWIntro::~AdminAMWIntro(){


}

const QString & AdminAMWIntro::cgetType()const{

    QString * res = new QString (QWizardPage::field("userType").toString());

    return *res;
}
