#include "memberupdatewview.h"

MemberUpdateWView::MemberUpdateWView(QWidget* ptr)
    : QWidget (ptr),
      name (new QLineEdit),
      surname (new QLineEdit),
      birth (new QLineEdit),
      phone (new QLineEdit),
      eMail (new QLineEdit),
      save (new QPushButton ( tr( "Salva") ) )
{

    name->setClearButtonEnabled( true );
    surname->setClearButtonEnabled( true );
    birth->setClearButtonEnabled( true );
    phone->setClearButtonEnabled( true );
    eMail->setClearButtonEnabled( true );

    QLabel* lName = new QLabel ( tr ( "Nome" ) );
    QLabel* lSurname = new QLabel ( tr("Cognome") );
    QLabel* lBirth = new QLabel ( tr ("Data di nascita" ) );
    QLabel* lPhone = new QLabel ( tr( "Telefono") );
    QLabel* lEMail = new QLabel ( tr("eMail") );

    QGridLayout* internal = new QGridLayout;

    internal->addWidget(lName, 0, 0);
    internal->addWidget(name, 0, 1);

    internal->addWidget(lSurname, 1, 0);
    internal->addWidget(surname, 1, 1);

    internal->addWidget(lBirth, 2, 0);
    internal->addWidget(birth, 2, 1);

    internal->addWidget(lPhone, 3, 0);
    internal->addWidget(phone, 3, 1);

    internal->addWidget(lEMail, 4, 0);
    internal->addWidget(eMail, 4, 1);

    internal->addWidget(save, 5, 1);

    QGroupBox* internalGroup = new QGroupBox ( tr ("Informazioni personali") );

    internalGroup->setLayout(internal);


    QPushButton* modifyHobby = new QPushButton ( tr("Modifica Hobby") );
    QPushButton* modifyInterests = new QPushButton ( tr ("Modifica Interessi") );

    QPushButton* modifyExperiences = new QPushButton ( tr("Modifica Esperienze") );

    QVBoxLayout* optionButton = new QVBoxLayout;

    optionButton->addWidget(modifyHobby);
    optionButton->addWidget(modifyInterests);
    optionButton->addWidget(modifyExperiences);

    QGroupBox* buttonOpt = new QGroupBox ( tr ("Altre modifiche" ));

    buttonOpt->setLayout(optionButton);

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(internalGroup);
    layoutTot->addWidget(buttonOpt);

    setLayout(layoutTot);

    setFixedSize( sizeHint() );

    /*connect (save,
             SIGNAL (clicked()),
             this,
             SIGNAL (saveBio()));*/

    connect (save,
             SIGNAL (clicked()),
             this,
             SLOT ( groupBio()) );

    connect (modifyHobby,
             SIGNAL (clicked()),
             this,
             SIGNAL (execModHobby()));

    connect (modifyInterests,
             SIGNAL (clicked()),
             this,
             SIGNAL (execModInterests()));

    connect (modifyExperiences,
             SIGNAL (clicked()),
             this,
             SIGNAL (execModExperiences()));

}

MemberUpdateWView::~MemberUpdateWView(){

    delete name;
    delete surname;
    delete birth;
    delete phone;
    delete eMail;

    delete save;
}

void MemberUpdateWView::setBio(const QString & sName,
                               const QString & sSurname,
                               const QString & sBirth,
                               const QString & sPhone,
                               const QString & sEMail){

    name->setText(sName);
    surname->setText(sSurname);
    birth->setText(sBirth);
    phone->setText(sPhone);
    eMail->setText(sEMail);
}

void MemberUpdateWView::groupBio()const{

    if (name->isModified() ||
            surname->isModified() ||
            birth->isModified() ||
            phone->isModified() ||
            eMail->isModified()) {

        emit saveBio(name->text(),
                     surname->text(),
                     birth->text(),
                     phone->text(),
                     eMail->text());

    }else{

        QMessageBox info (QMessageBox::Information,
                          tr ("Modifica informazioni personali"),
                          tr ("È nesessario eseguire delle modifiche per<br>"
                              "poter salvare.") );

        info.exec();
    }


}

void MemberUpdateWView::closeEvent(QCloseEvent * event){

    emit requestClose(event);
}
