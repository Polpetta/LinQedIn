#include "mviewerview.h"

void MViewerView::initialize(){

    nick = new QLabel;
    name = new QLabel;
    surname = new QLabel;
    birth = new QLabel;
    phone = new QLabel;
    eMail = new QLabel;
    layoutTot = new QVBoxLayout;
    hobby = new listViewer;
    interests = new listViewer;
    experiences = new listViewer;
    friendships = new listViewer;
    credentialBox = new QGroupBox( tr("Credenziali Membro") );
    bioBox = new QGroupBox( tr("Informazioni personali") );
    friendshipsBox = new QGroupBox( tr("Amicizie") );
    hobbyBox = new QGroupBox( tr("Hobby") );
    interestsBox = new QGroupBox( tr("Interessi") );
    experiencesBox = new QGroupBox( tr("Esperienze") );
    crdLayout = new QGridLayout;
    bioLayout = new QGridLayout;
    scrollFriendships = new QScrollArea;
    friendshipsLayout = new QGridLayout;
    scrollHobby = new QScrollArea;
    hobbyLayout = new QGridLayout;
    scrollInterests = new QScrollArea;
    interestsLayout = new QGridLayout;
    scrollExperiences = new QScrollArea;
    experiencesLayout = new QGridLayout;
}

void MViewerView::clearList(){

    hobby->clear();
    interests->clear();
    experiences->clear();
    friendships->clear();

    delete hobby;
    delete interests;
    delete experiences;
    delete friendships;

    hobby = new listViewer;
    interests = new listViewer;
    experiences = new listViewer;
    friendships = new listViewer;
}

void MViewerView::build(){

    QLabel* lNick = new QLabel (tr ("Nickname: ") );
    QLabel* lName = new QLabel (tr ("Nome: ") );
    QLabel* lSurname = new QLabel (tr ("Cognome: ") );
    QLabel* lBirth = new QLabel (tr ("Data di nascita: ") );
    QLabel* lPhone = new QLabel (tr ("Telefono: ") );
    QLabel* leMail = new QLabel (tr ("eMail: ") );


    crdLayout->addWidget(lNick, 0, 0);
    crdLayout->addWidget(nick, 0, 1);

    credentialBox->setLayout(crdLayout);


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

    scrollFriendships->setWidget(friendships);
    scrollFriendships->setWidgetResizable( true );

    friendshipsLayout->addWidget(scrollFriendships);

    friendshipsBox->setLayout(friendshipsLayout);



    scrollHobby->setWidget(hobby);
    scrollHobby->setWidgetResizable( true );

    hobbyLayout->addWidget(scrollHobby);

    hobbyBox->setLayout(hobbyLayout);



    scrollInterests->setWidget(interests);
    scrollInterests->setWidgetResizable( true );

    interestsLayout->addWidget(scrollInterests);

    interestsBox->setLayout(interestsLayout);


    scrollExperiences->setWidget(experiences);
    scrollExperiences->setWidgetResizable( true );

    experiencesLayout->addWidget(scrollExperiences);

    experiencesBox->setLayout(experiencesLayout);



    setLayout(layoutTot);
}

MViewerView::MViewerView(QWidget* ptr)
    : QWidget (ptr)
{

    initialize();
    build();

}

MViewerView::~MViewerView(){

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

    delete credentialBox;
    delete bioBox;
    delete friendshipsBox;
    delete hobbyBox;
    delete interestsBox;
    delete experiencesBox;

    delete crdLayout;

    delete bioLayout;

    delete scrollFriendships;
    delete friendshipsLayout;

    delete scrollHobby;
    delete hobbyLayout;

    delete scrollInterests;
    delete interestsLayout;

    delete scrollExperiences;
    delete experiencesLayout;

    delete layoutTot;
}

void MViewerView::setProfile(const QString & pNick,
                             const QString & pName,
                             const QString & pSurname,
                             const QString & pBirth,
                             const QString & pPhone,
                             const QString & pEMail,
                             const QVector<QString> & pFriendships,
                             const QVector<QString> & pHobby,
                             const QVector<QString> & pInterests,
                             const QVector<QString> & pExperiences){

    nick->setText(pNick);
    name->setText(pName);
    surname->setText(pSurname);
    birth->setText(pBirth);
    phone->setText(pPhone);
    eMail->setText(pEMail);

    QVector<QString>::const_iterator its;

    //friendships
    for (its = pFriendships.cbegin(); its != pFriendships.cend(); ++its){

        QLabel* newFriend = new QLabel (*its);

        friendships->addLabel(newFriend);
    }
    if (pFriendships.size() == 0)
        friendships->addLabel(new QLabel(tr ("Non ci sono amici")));

    //hobby
    for (its = pHobby.cbegin(); its != pHobby.cend(); ++its){

        QLabel* newHobby = new QLabel (*its);

        hobby->addLabel(newHobby);
    }
    if (pHobby.size() == 0)
        hobby->addLabel(new QLabel( tr("Non ci sono hobby")));

    //interests
    for (its = pInterests.cbegin(); its != pInterests.cend(); ++its){

        QLabel* newInterests = new QLabel (*its);

        interests->addLabel(newInterests);
    }
    if (pInterests.size() == 0)
        interests->addLabel(new QLabel( tr("Non ci sono interessi")));

    //experiences
    for (its = pExperiences.cbegin(); its != pExperiences.cend(); ++its){

        QLabel* newExperiences = new QLabel (*its);

        experiences->addLabel(newExperiences);
    }
    if (pExperiences.size() == 0)
        experiences->addLabel(new QLabel( tr("Non ci sono esperienze passate") ));
}

QVBoxLayout* MViewerView::getLayout()const{

    return layoutTot;
}

void MViewerView::resetLayout(){

    delete layoutTot; //cancella tutto quanto è "contenuto" in essa

    layoutTot = new QVBoxLayout; //nuovo layout da ripopolare

    clearList();
    build();

}

QGroupBox* MViewerView::getCredential()const{

    return credentialBox;
}

QGroupBox* MViewerView::getBio()const{

    return bioBox;
}

QGroupBox* MViewerView::getFriendships()const{

    return friendshipsBox;
}

QGroupBox* MViewerView::getHobby()const{

    return hobbyBox;
}

QGroupBox* MViewerView::getInterests()const{

    return interestsBox;
}

QGroupBox* MViewerView::getExperiences()const{

    return experiencesBox;
}

void MViewerView::show(){

    setToShow();

    setMinimumSize( sizeHint() );

    QWidget::show();
}
