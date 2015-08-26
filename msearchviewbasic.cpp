#include "msearchviewbasic.h"

MSearchViewBasic::MSearchViewBasic(QWidget* ptr)
    : MSearchView(ptr)
{

    /* Per MSearchViewBusiness sta parte
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
    */
}


MSearchViewBasic::~MSearchViewBasic(){

}

void MSearchViewBasic::commitSearch()const{

    emit searchConfirm(MSearchView::getNameTex(),
                       MSearchView::getSurnameTex(),
                       MSearchView::getBirthDayTex());
}
