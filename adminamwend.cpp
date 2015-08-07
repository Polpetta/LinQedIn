#include "adminamwend.h"

AdminAMWEnd::AdminAMWEnd(QWizard* ptr)
    : QWizardPage (ptr)
{

    setTitle( tr ("Completamento operazione") );

    QLabel* message = new QLabel ( tr ("La procedura guidata è terminata."));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(message);

    setLayout(layout);
}

AdminAMWEnd::~AdminAMWEnd(){


}
