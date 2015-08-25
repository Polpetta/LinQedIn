#include "msearchview.h"

MSearchView::MSearchView(QWidget* ptr)
    : QWidget (ptr),
      nameEdit(new QLineEdit),
      surnameEdit(new QLineEdit),
      birthDayEdit(new QLineEdit),
      search(new QPushButton ( tr ("Cerca") )),
      result(new TableSearch),
      scrollResults(new QScrollArea),
      layoutTot(new QVBoxLayout)
{

    birthDayEdit->setEnabled( false );

    QLabel* note = new QLabel ( tr("<i>Nota:</i> le date vanno espresse nel"
                                   " formato dd-mm-yyyy") );

    QLabel* name = new QLabel ( tr ("Nome") );
    QLabel* surname = new QLabel ( tr("Cognome") );
    QLabel* birthDay = new QLabel ( tr("Data nascita") );

    nameEdit->setClearButtonEnabled( true );
    surnameEdit->setClearButtonEnabled( true );
    birthDayEdit->setClearButtonEnabled( true );

    QGridLayout* layoutBio = new QGridLayout;

    layoutBio->addWidget(name, 0, 0);
    layoutBio->addWidget(nameEdit, 0, 1);

    layoutBio->addWidget(surname, 1, 0);
    layoutBio->addWidget(surnameEdit, 1, 1);

    layoutBio->addWidget(birthDay, 2, 0);
    layoutBio->addWidget(birthDayEdit, 2, 1);

    QGroupBox* generic = new QGroupBox ( tr("Ricerca Generica") );

    generic->setLayout(layoutBio);

    scrollResults->setWidget(result);

    scrollResults->setWidgetResizable( true );
    scrollResults->setFixedHeight(200);

    layoutTot->addWidget(scrollResults);
    layoutTot->addWidget(search);
    layoutTot->addWidget(note);
    layoutTot->addWidget(generic);

    setLayout(layoutTot);

    setMinimumSize( sizeHint() );

    connect (search,
             SIGNAL (clicked()),
             this,
             SLOT (commitSearch()));
}

MSearchView::~MSearchView(){

    delete nameEdit;
    delete surnameEdit;
    delete birthDayEdit;

    delete layoutTot;
}

TableSearch* MSearchView::getTable()const{

    return result;
}

void MSearchView::closeEvent( QCloseEvent* event){

    emit requestClose(event);
}

QVBoxLayout* MSearchView::getLayout()const{

    return layoutTot;
}

void MSearchView::enableBirthDay()const{

    birthDayEdit->setEnabled( true );
}

QString MSearchView::getNameTex()const{

    return nameEdit->text();
}

QString MSearchView::getSurnameTex()const{

    return surnameEdit->text();
}

QString MSearchView::getBirthDayTex()const{

    return birthDayEdit->text();
}
