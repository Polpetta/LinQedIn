#include "adminrmmemberwview.h"

AdminRmMemberWView::AdminRmMemberWView(QWidget* ptr)
    : QWidget (ptr)
{


    QLabel* note = new QLabel ( tr ("<i>Nota</i>: questa operazione non"
                                    " può essere annullata") );

    QLabel* info = new QLabel ( tr ("Per cancellare un utente inserire il"
                                    " suo nickname") );
    target = new QLineEdit;

    QPushButton* confirmButton = new QPushButton ( tr ("Rimuovere") );

    target->setClearButtonEnabled( true );

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(note);
    layout->addWidget(info);
    layout->addWidget(target);
    layout->addWidget(confirmButton);

    setLayout(layout);

    setFixedSize( sizeHint() );

    //da farci le varie connect
}

AdminRmMemberWView::~AdminRmMemberWView(){

    delete target;
}

void AdminRmMemberWView::closeEvent(QCloseEvent * event){

    emit requestClose(event);
}
