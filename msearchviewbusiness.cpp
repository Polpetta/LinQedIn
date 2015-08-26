#include "msearchviewbusiness.h"

MSearchViewBusiness::MSearchViewBusiness(QWidget * ptr)
    : MSearchViewBasic(ptr),
      hobbyEdit(new QLineEdit),
      addHobby(new QPushButton( tr("Filtra") ))
{

    QLabel* hobby = new QLabel ( tr("Hobby") );
    hobbyEdit->setClearButtonEnabled( true );

    QGridLayout* layoutOpt = new QGridLayout;
    layoutOpt->addWidget(hobby, 0, 0);
    layoutOpt->addWidget(hobbyEdit, 0, 1);
    layoutOpt->addWidget(addHobby, 0, 2);

    QGroupBox* opt = new QGroupBox ( tr("Filtro Hobby") );

    opt->setLayout(layoutOpt);

    MSearchView::getLayout()->addWidget(opt);


    connect (addHobby,
             SIGNAL (clicked()),
             this,
             SLOT (addFilterH()));
}

MSearchViewBusiness::~MSearchViewBusiness(){

    delete hobbyEdit;
    delete addHobby;
}

void MSearchViewBusiness::warnFilter()const{

    QMessageBox info(QMessageBox::Warning,
                     tr("Errore aggiunta filtro"),
                     tr ("Completare il form per gli Hobby"));

    info.exec();
}

void MSearchViewBusiness::addFilterH()const{

    if (hobbyEdit->isModified()){

        emit emitNewHobby(hobbyEdit->text());
        hobbyEdit->clear();
    }else
        warnFilter();
}
