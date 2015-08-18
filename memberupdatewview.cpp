#include "memberupdatewview.h"

MemberUpdateWView::MemberUpdateWView(QWidget* ptr)
    : QWidget (ptr),
      name (new QLineEdit),
      surname (new QLineEdit),
      birth (new QLineEdit),
      phone (new QLineEdit),
      eMail (new QLineEdit),
      save (new QPushButton ( tr( "Salva") ) ),

      modifyHobby (new QLineEdit),
      hobby (new listViewer),
      addHobby( new QPushButton ( tr("Aggiungi") )),
      rmHobby  (new QPushButton ( tr("Rimuovi") )),

      modifyInterests (new QLineEdit),
      interests (new listViewer),
      addInterests (new QPushButton ( tr("Aggiungi") )),
      rmInterests (new QPushButton ( tr("Rimuovi") )),

      modifyExpBegin (new QLineEdit),
      modifyExpFinish(new QLineEdit),
      modifyExpDesc (new QLineEdit),
      modifyExpWhere(new QLineEdit),
      experiences (new listViewer),
      addExperiences (new QPushButton ( tr ("Aggiungi") )),
      rmExperiences (new QPushButton ( tr("Rimuovi") ))
{

    name->setClearButtonEnabled( true );
    surname->setClearButtonEnabled( true );
    birth->setClearButtonEnabled( true );
    phone->setClearButtonEnabled( true );
    eMail->setClearButtonEnabled( true );

    modifyHobby->setClearButtonEnabled( true );
    modifyInterests->setClearButtonEnabled( true );

    modifyExpBegin->setClearButtonEnabled( true );
    modifyExpFinish->setClearButtonEnabled( true );
    modifyExpDesc->setClearButtonEnabled( true );
    modifyExpWhere->setClearButtonEnabled( true );

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

    //hobby
    QScrollArea* scrollHobby = new QScrollArea;

    scrollHobby->setWidget(hobby);
    scrollHobby->setWidgetResizable( true );

    QGridLayout* hobbyButton = new QGridLayout;

    hobbyButton->addWidget(addHobby, 0, 0);
    hobbyButton->addWidget(rmHobby, 0, 1);

    QVBoxLayout* hobbyL = new QVBoxLayout;

    hobbyL->addWidget(scrollHobby);
    hobbyL->addWidget(modifyHobby);
    hobbyL->addLayout(hobbyButton);

    QGroupBox* hobbyGroup = new QGroupBox ( tr("Modifica hobby") );

    hobbyGroup->setLayout(hobbyL);
    //...

    //interests
    QScrollArea* scrollInterests = new QScrollArea;

    scrollInterests->setWidget(interests);
    scrollInterests->setWidgetResizable( true );

    QGridLayout* interestsButton = new QGridLayout;

    interestsButton->addWidget(addInterests, 0 , 0);
    interestsButton->addWidget(rmInterests, 0, 1);

    QVBoxLayout* interestsL = new QVBoxLayout;

    interestsL->addWidget(scrollInterests);
    interestsL->addWidget(modifyInterests);
    interestsL->addLayout(interestsButton);

    QGroupBox* interestsGroup = new QGroupBox ( tr("Modifica Interessi") );

    interestsGroup->setLayout(interestsL);
    //...


    //Experiences
    QScrollArea* scrollExp = new QScrollArea;

    QLabel* lBegin = new QLabel (tr ("Inizio") );
    QLabel* lFinish = new QLabel (tr("Fine") );
    QLabel* lDesc = new QLabel ( tr ("Breve descrizione") );
    QLabel* lWhere = new QLabel ( tr("Dove" ) );

    QGridLayout* formGrid = new QGridLayout;

    formGrid->addWidget(lBegin, 0, 0);
    formGrid->addWidget(modifyExpBegin, 0, 1);
    formGrid->addWidget(lFinish, 1, 0);
    formGrid->addWidget(modifyExpFinish, 1, 1);
    formGrid->addWidget(lDesc, 2, 0);
    formGrid->addWidget(modifyExpDesc, 2, 1);
    formGrid->addWidget(lWhere, 3, 0);
    formGrid->addWidget(modifyExpWhere, 3, 1);

    scrollExp->setWidget(experiences);
    scrollExp->setWidgetResizable( true );

    QGridLayout* expButton = new QGridLayout;

    expButton->addWidget(addExperiences, 0, 0);
    expButton->addWidget(rmExperiences, 0, 1);

    QVBoxLayout* expL = new QVBoxLayout;

    expL->addWidget(scrollExp);
    expL->addLayout(formGrid);
    expL->addLayout(expButton);

    QGroupBox* experienceGroup = new QGroupBox ( tr ("Modifica le Esperienze") );

    experienceGroup->setLayout(expL);
    //...

    QVBoxLayout* optionButton = new QVBoxLayout;

    optionButton->addWidget(hobbyGroup);
    optionButton->addWidget(interestsGroup);

    QHBoxLayout* horizL = new QHBoxLayout;

    horizL->addLayout(optionButton);
    horizL->addWidget(experienceGroup);

    QGroupBox* buttonOpt = new QGroupBox ( tr ("Altre modifiche" ));

    buttonOpt->setLayout(horizL);

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(internalGroup);
    layoutTot->addWidget(buttonOpt);

    setLayout(layoutTot);

    setFixedSize( sizeHint() );

    connect (save,
             SIGNAL (clicked()),
             this,
             SLOT ( groupBio()) );

    connect (addHobby,
             SIGNAL (clicked()),
             this,
             SLOT ( emitAddHobby() ));

    connect (rmHobby,
             SIGNAL (clicked()),
             this,
             SLOT ( emitRmHobby() ));

    connect (addInterests,
             SIGNAL (clicked()),
             this,
             SLOT (emitAddInterests() ));

    connect (rmInterests,
             SIGNAL (clicked()),
             this,
             SLOT ( emitRmInterests() ));

    /*connect (addHobby,
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

    * Da rifare le connect
*/

}

MemberUpdateWView::~MemberUpdateWView(){

    delete name;
    delete surname;
    delete birth;
    delete phone;
    delete eMail;

    delete save;


    delete modifyHobby;
    delete hobby;

    delete addHobby;
    delete rmHobby;


    delete modifyInterests;
    delete interests;

    delete addInterests;
    delete rmInterests;


    delete modifyExpBegin;
    delete modifyExpFinish;
    delete modifyExpDesc;
    delete modifyExpWhere;
    delete experiences;

    delete addExperiences;
    delete rmExperiences;

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

void MemberUpdateWView::info(const QString &type, const typeAction &act) const{

    QString action = tr ("unknown"); //in caso capiti qualcosa di strano
    if (act == typeAction::insert){

        action = tr ("inserire");
    }else if (act == typeAction::remove){

        action = tr ("rimuovere");
    }


    QString title = tr("Aggiunta ")+type;
    QString message = tr("È necessario completare il form per<br> ")+action+tr(" un ")+type;

    QMessageBox info(QMessageBox::Information,
                     title,
                     message);

    info.exec();
}

void MemberUpdateWView::emitAddHobby() const{

    if (modifyHobby->isModified()){

        emit execAddHobby(modifyHobby->text());
        modifyHobby->clear();
    }else{

        info("hobby",typeAction::insert);
    }
}

void MemberUpdateWView::emitRmHobby()const{

    if (modifyHobby->isModified()){

        emit execRmHobby(modifyHobby->text());
        modifyHobby->clear();
    }else{

        info("hobby",typeAction::remove);
    }
}

void MemberUpdateWView::emitAddInterests()const{

    if (modifyInterests->isModified()){

        emit execAddInterests(modifyInterests->text());
        modifyInterests->clear();
    }else{

        info("interesse",typeAction::insert);
    }
}

void MemberUpdateWView::emitRmInterests()const{

    if (modifyInterests->isModified()){

        emit execRmInterests(modifyInterests->text());
        modifyInterests->clear();
    }else{

        info("interesse",typeAction::remove);
    }
}

listViewer* MemberUpdateWView::getHobbyList()const{

    return hobby;
}

listViewer* MemberUpdateWView::getInterestsList()const{

    return interests;
}
