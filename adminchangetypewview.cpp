#include "adminchangetypewview.h"

AdminChangeTypeWView::AdminChangeTypeWView(QWidget* ptr)
    : QWidget (ptr),
      nick(new QLineEdit),
      newType(new QLineEdit)
{

    QLabel* note = new QLabel ( tr("I tipi possibili per il cambiamento sono:<br>"
                                   "-<i>Busic</i><br>"
                                   "-<i>Business</i><br>"
                                   "-<i>Executive</i><br>") );

    QLabel* lNick = new QLabel ( tr("Nick: ") );
    QLabel* lType = new QLabel ( tr ("Nuovo tipo: ") );

    QPushButton* exec = new QPushButton ( tr( "Esegui") );

    nick->setClearButtonEnabled( true );
    newType->setClearButtonEnabled( true );

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(lNick);
    layout->addWidget(nick);

    layout->addWidget(lType);
    layout->addWidget(newType);

    layout->addWidget(note);

    layout->addWidget(exec);

    setLayout(layout);

    setFixedSize( sizeHint () );

    connect (exec,
             SIGNAL (clicked()),
             this,
             SLOT (execChangeType()));
}

void AdminChangeTypeWView::execChangeType()const{

    const QString & nNick = nick->text();

    const QString & nType = newType->text();

    nick->clear();
    newType->clear();

    emit changeType(nNick, nType);
}

void AdminChangeTypeWView::closeEvent(QCloseEvent * event){

    emit requestClose (event);
}
