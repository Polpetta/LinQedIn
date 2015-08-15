#include "memberloginwview.h"

MemberLoginWView::MemberLoginWView(QWidget* ptr)
    : QWidget (ptr),
      nickLogin (new QLineEdit)
{

    QLabel* note = new QLabel ( tr("Inserisci le tue credenziali") );

    nickLogin->setClearButtonEnabled( true );

    QPushButton* logButton = new QPushButton ( tr ( "Login") );

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(note);
    layout->addWidget(nickLogin);
    layout->addWidget(logButton);

    setLayout (layout);

    setFixedSize( sizeHint() );

}

MemberLoginWView::~MemberLoginWView(){

    delete nickLogin;
}
