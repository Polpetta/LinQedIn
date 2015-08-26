#include "adminmwviewerview.h"

AdminMWViewerView::AdminMWViewerView(QWidget* ptr)
    : QWidget (ptr),
      nick (new QLabel),
      name (new QLabel),
      surname (new QLabel),
      birth (new QLabel),
      phone (new QLabel),
      eMail (new QLabel),
      scrollHobby(new QScrollArea),
      scrollInterests(new QScrollArea),
      scrollExperience(new QScrollArea),
      scrollFriendships(new QScrollArea),
      hobby(new listViewer),
      interests(new listViewer),
      experiences(new listViewer),
      friendships(new listViewer)
{

    QLabel* lNick = new QLabel (tr ("Nickname: ") );
    QLabel* lName = new QLabel (tr ("Nome: ") );
    QLabel* lSurname = new QLabel (tr ("Cognome: ") );
    QLabel* lBirth = new QLabel (tr ("Data di nascita: ") );
    QLabel* lPhone = new QLabel (tr ("Telefono: ") );
    QLabel* leMail = new QLabel (tr ("eMail: ") );

    QGroupBox* credentialBox = new QGroupBox ( tr ("Credenziali Membro") );
    QGridLayout* crdLayout = new QGridLayout;

    crdLayout->addWidget(lNick, 0 ,0);
    crdLayout->addWidget(nick, 0, 1);

    credentialBox->setLayout(crdLayout);

    QGroupBox* bioBox = new QGroupBox ( tr ("Informazioni personali ") );
    QGridLayout* bioLayout = new QGridLayout;

    bioLayout->addWidget(lName, 0, 0);
    bioLayout->addWidget(name, 0, 1);

    bioLayout->addWidget(lSurname, 1 ,0);
    bioLayout->addWidget(surname, 1, 1);

    bioLayout->addWidget(lBirth, 2, 0);
    bioLayout->addWidget(birth, 2, 1);

    bioLayout->addWidget(lPhone, 3, 0);
    bioLayout->addWidget(phone, 3, 1);

    bioLayout->addWidget(leMail, 4, 0);
    bioLayout->addWidget(eMail, 4, 1);

    bioBox->setLayout(bioLayout);


    QGroupBox* hobbyBox = new QGroupBox ( tr("Hobby") );
    QGridLayout* hobbyLayout = new QGridLayout;

    scrollHobby->setWidget(hobby);
    scrollHobby->setWidgetResizable( true );

    hobbyLayout->addWidget(scrollHobby);

    hobbyBox->setLayout(hobbyLayout);


    QGroupBox* interestsBox = new QGroupBox ( tr ("Interessi" ) );
    QGridLayout* interestsLayout = new QGridLayout;

    scrollInterests->setWidget(interests);
    scrollInterests->setWidgetResizable( true );

    interestsLayout->addWidget(scrollInterests);

    interestsBox->setLayout(interestsLayout);


    QGroupBox* experiencesBox = new QGroupBox ( tr ("Esperienze") );
    QGridLayout* experiencesLayout = new QGridLayout;

    scrollExperience->setWidget(experiences);
    scrollExperience->setWidgetResizable( true );

    experiencesLayout->addWidget(scrollExperience);

    experiencesBox->setLayout(experiencesLayout);


    QGroupBox* friendshipsBox = new QGroupBox ( tr ("Amicizie") );
    QGridLayout* friendshipsLayout = new QGridLayout;

    scrollFriendships->setWidget(friendships);
    scrollFriendships->setWidgetResizable( true );

    friendshipsLayout->addWidget(scrollFriendships);

    friendshipsBox->setLayout(friendshipsLayout);

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(credentialBox);
    layoutTot->addWidget(bioBox);
    layoutTot->addWidget(hobbyBox);
    layoutTot->addWidget(interestsBox);
    layoutTot->addWidget(experiencesBox);
    layoutTot->addWidget(friendshipsBox);

    setLayout(layoutTot);

    /*
     * Le classi per visualizzare gli hobby, interessi e esperienze posso farle
     * interne a questa classe perchè a differenza di tableSearch che mi può
     * servire anche in member queste mi servono solo per questa classe e non
     * voglio renderle pubbliche.
     */


}


AdminMWViewerView::~AdminMWViewerView(){

    delete nick;
    delete name;
    delete surname;
    delete birth;
    delete phone;
    delete eMail;

    delete hobby;
    delete interests;
    delete experiences;
    delete friendships;

    delete scrollHobby;
    delete scrollInterests;
    delete scrollExperience;
    delete scrollFriendships;
}

void AdminMWViewerView::setProfile(const QString & pNick,
                                   const QString & pName,
                                   const QString & pSurname,
                                   const QString & pBirth,
                                   const QString & pPhone,
                                   const QString & pEMail,
                                   const QVector<QString> & pHobby,
                                   const QVector<QString> & pInterests,
                                   const QVector<QString> & pExperience,
                                   const QVector<QString> & pFriendships){

    hobby->clear();
    interests->clear();

    experiences->clear();

    friendships->clear();


    nick->setText(pNick);
    name->setText(pName);
    surname->setText(pSurname);
    birth->setText(pBirth);
    phone->setText(pPhone);
    eMail->setText(pEMail);

    QVector<QString>::const_iterator its;
    for (its = pHobby.cbegin(); its != pHobby.cend(); ++its){

        QLabel* newHobby = new QLabel (*its);

        hobby->addLabel(newHobby);
    }
    for (its = pInterests.cbegin(); its != pInterests.cend(); ++its){

        QLabel* newInterests = new QLabel (*its);

        interests->addLabel(newInterests);
    }

    for (its = pExperience.cbegin(); its != pExperience.cend(); ++its){

        QLabel* newEvent = new QLabel(*its);

        experiences->addLabel(newEvent);
    }

    for (its = pFriendships.cbegin(); its != pFriendships.cend(); ++its){

        QLabel* newFriend = new QLabel (*its);

        friendships->addLabel(newFriend);
    }

    if (pHobby.size() == 0)
        hobby->addLabel(new QLabel( tr("Non ci sono hobby")));

    if (pInterests.size() == 0)
        interests->addLabel(new QLabel( tr("Non ci sono interessi")));

    if (pExperience.size() == 0)
        experiences->addLabel(new QLabel( tr("Non ci sono esperienze passate") ));


    if (pFriendships.size() == 0)
        friendships->addLabel(new QLabel(tr ("Non ci sono amici")));
}
