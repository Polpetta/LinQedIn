#include "msearchviewexecutive.h"

MSearchViewExecutive::MSearchViewExecutive(QWidget* ptr)
    : MSearchViewBusiness(ptr),
      interestsEdit(new QLineEdit),
      addInterests(new QPushButton(tr ("Filtra") ))
{

    QLabel* interests = new QLabel ( tr("Interesse") );
    interestsEdit->setClearButtonEnabled( true );

    QGridLayout* layoutOpt = new QGridLayout;

    layoutOpt->addWidget(interests, 0, 0);
    layoutOpt->addWidget(interestsEdit, 0, 1);
    layoutOpt->addWidget(addInterests, 0, 2);

    QGroupBox* opt = new QGroupBox (tr ("Filtro Interessi") );

    opt->setLayout(layoutOpt);

    MSearchView::getLayout()->addWidget(opt);

    connect (addInterests,
             SIGNAL (clicked()),
             this,
             SLOT (addFilterI()));
}

MSearchViewExecutive::~MSearchViewExecutive(){

    delete interestsEdit;
    delete addInterests;
}

void MSearchViewExecutive::warnFilter()const{

    QMessageBox info(QMessageBox::Warning,
                     tr("Errore aggiunta filtro"),
                     tr ("Completare il form per gli Interessi"));

    info.exec();
}

void MSearchViewExecutive::addFilterI()const{

    if (interestsEdit->isModified()){

        emit emitNewInterests(interestsEdit->text());
        interestsEdit->clear();
    }else
        warnFilter();
}
