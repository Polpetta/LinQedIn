#include "adminamwintro.h"

AdminAMWIntro::AdminAMWIntro(QWidget * ptr)
    : QWizardPage(ptr)
{

    setTitle( tr ("Aggiunta nuovo Iscritto") );

    QLabel* intro = new QLabel( tr("La procedura guidata vi permetterà di "
                                   "aggiungere un nuovo Iscritto.") );

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(intro);

    setLayout(layout);
}

AdminAMWIntro::~AdminAMWIntro(){


}
