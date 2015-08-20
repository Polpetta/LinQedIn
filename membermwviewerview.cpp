#include "membermwviewerview.h"

MemberMWViewerView::MemberMWViewerView(QWidget* ptr)
    : QWidget(ptr),
      nick (new QLabel),
      name (new QLabel),
      surname (new QLabel),
      birth(new QLabel),
      phone(new QLabel),
      eMail(new QLabel),
      layoutTot(new QVBoxLayout),
      hobby(nullptr),
      interests(nullptr),
      experiences(nullptr),
      friendships(nullptr)
{

    QLabel* lNick = new QLabel (tr ("Nickname: ") );
    QLabel* lName = new QLabel (tr ("Nome: ") );
    QLabel* lSurname = new QLabel (tr ("Cognome: ") );
    QLabel* lBirth = new QLabel (tr ("Data di nascita: ") );
    QLabel* lPhone = new QLabel (tr ("Telefono: ") );
    QLabel* leMail = new QLabel (tr ("eMail: ") );

    QGroupBox* credentialBox = new QGroupBox (tr ("Credenziali Membro") );
    QGridLayout* crdLayout = new QGridLayout;

    crdLayout->addWidget(lNick, 0, 0);
    crdLayout->addWidget(nick, 0, 1);

    credentialBox->setLayout(crdLayout);

    QGroupBox* bioBox = new QGroupBox (tr ("Informazioni personali") );
    QGridLayout* bioLayout = new QGridLayout;

    bioLayout->addWidget(lName, 0, 0);
    bioLayout->addWidget(name, 0, 1);

    bioLayout->addWidget(lSurname, 1, 0);
    bioLayout->addWidget(surname, 1, 1);

    bioLayout->addWidget(lBirth, 2, 0);
    bioLayout->addWidget(birth, 2, 1);

    bioLayout->addWidget(lPhone, 3, 0);
    bioLayout->addWidget(phone, 3, 1);

    bioLayout->addWidget(leMail, 4, 0);
    bioLayout->addWidget(eMail, 4, 1);

    bioBox->setLayout(bioLayout);

    layoutTot->addWidget(credentialBox);
    layoutTot->addWidget(bioBox);

    setLayout(layoutTot);

    setMinimumSize( sizeHint() );
}

MemberMWViewerView::~MemberMWViewerView(){

    delete nick;
    delete name;
    delete surname;
    delete birth;
    delete phone;
    delete eMail;

    delete layoutTot;

    if (hobby != nullptr)
        delete hobby;

    if (interests != nullptr)
        delete interests;

    if (experiences != nullptr)
        delete experiences;

    if (friendships != nullptr)
        delete friendships;
}

void MemberMWViewerView::addHobby(const QVector<QString> &pHobby){

    qDebug()<<"Aggiunti hobby";

    hobby = new listViewer;

    QVector<QString>::const_iterator its;
    for (its = pHobby.cbegin(); its != pHobby.cend(); ++its){

        QLabel* newHobby = new QLabel (*its);

        hobby->addLabel(newHobby);
    }

    QScrollArea* scrollHobby = new QScrollArea;
    QGroupBox* hobbyBox = new QGroupBox (tr("Hobby") );
    QGridLayout* hobbyLayout = new QGridLayout;

    scrollHobby->setWidget(hobby);
    scrollHobby->setWidgetResizable( true );

    hobbyLayout->addWidget(scrollHobby);

    hobbyBox->setLayout(hobbyLayout);

    layoutTot->addWidget(hobbyBox);

   setMinimumSize( sizeHint() ); //ricalcolo la finestra

    if (pHobby.size() == 0)
        hobby->addLabel(new QLabel( tr("Non ci sono hobby")));
}

void MemberMWViewerView::addInterests(const QVector<QString> & pInterests){

    qDebug()<<"Aggiunti interessi";

    interests = new listViewer;

    QVector<QString>::const_iterator its;

    for (its = pInterests.cbegin(); its != pInterests.cend(); ++its){

        QLabel* newInterests = new QLabel (*its);

        interests->addLabel(newInterests);
    }

    QScrollArea* scrollInterests = new QScrollArea;
    QGroupBox* interestsBox = new QGroupBox( tr("Interessi") );
    QGridLayout* interestsLayout = new QGridLayout;

    scrollInterests->setWidget(interests);
    scrollInterests->setWidgetResizable( true );

    interestsLayout->addWidget(scrollInterests);

    interestsBox->setLayout(interestsLayout);

    layoutTot->addWidget(interestsBox);

    setMinimumSize( sizeHint() );

    if (pInterests.size() == 0)
        interests->addLabel(new QLabel( tr("Non ci sono interessi")));
}

void MemberMWViewerView::addExperiences(const QVector<QString> &pExperiences){

    qDebug()<<"Aggiunte esperienze";

    experiences = new listViewer;

    QVector<QString>::const_iterator its;

    for (its = pExperiences.cbegin(); its != pExperiences.cend(); ++its){

        QLabel* newExperiences = new QLabel (*its);

        interests->addLabel(newExperiences);
    }

    QScrollArea* scrollExperiences = new QScrollArea;
    QGroupBox* experiencesBox = new QGroupBox ( tr("Esperienze") );
    QGridLayout* experiencesLayout = new QGridLayout;

    scrollExperiences->setWidget(experiences);
    scrollExperiences->setWidgetResizable( true );

    experiencesLayout->addWidget(scrollExperiences);

    experiencesBox->setLayout(experiencesLayout);

    layoutTot->addWidget(experiencesBox);

    setMinimumSize( sizeHint() );

    if (pExperiences.size() == 0)
        experiences->addLabel(new QLabel( tr("Non ci sono esperienze passate") ));
}

void MemberMWViewerView::setProfile(const QString & pNick,
                                    const QString & pName,
                                    const QString & pSurname,
                                    const QString & pBirth,
                                    const QString & pPhone,
                                    const QString & pEMail,
                                    const QVector<QString> & pFriendships){

    qDebug()<<"Settaggio profilo di base";

    friendships = new listViewer;

    nick->setText(pNick);
    name->setText(pName);
    surname->setText(pSurname);
    birth->setText(pBirth);
    phone->setText(pPhone);
    eMail->setText(pEMail);

    QVector<QString>::const_iterator its;

    for (its = pFriendships.cbegin(); its != pFriendships.cend(); ++its){

        QLabel* newFriend = new QLabel (*its);

        friendships->addLabel(newFriend);
    }

    if (pFriendships.size() == 0)
        friendships->addLabel(new QLabel(tr ("Non ci sono amici")));

    QScrollArea* scrollFriendships = new QScrollArea;
    QGroupBox* friendshipsBox = new QGroupBox( tr("Amicizie") );
    QGridLayout* friendshipsLayout = new QGridLayout;

    scrollFriendships->setWidget(friendships);
    scrollFriendships->setWidgetResizable( true );

    friendshipsLayout->addWidget(scrollFriendships);

    friendshipsBox->setLayout(friendshipsLayout);

    layoutTot->addWidget(friendshipsBox);

    setMinimumSize( sizeHint() );

}
