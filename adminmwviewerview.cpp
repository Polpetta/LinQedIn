#include "adminmwviewerview.h"

AdminMWViewerView::AdminMWViewerView(QWidget* ptr)
    : QWidget (ptr),
      nick (new QLabel),
      name (new QLabel),
      surname (new QLabel),
      birth (new QLabel),
      phone (new QLabel),
      eMail (new QLabel)
{

    QLabel* lNick = new QLabel (tr ("Nickname: ") );
    QLabel* lName = new QLabel (tr ("Nome: ") );
    QLabel* lSurname = new QLabel (tr ("Cognome: ") );
    QLabel* lBirth = new QLabel (tr ("Data di nascita: ") );
    QLabel* lPhone = new QLabel (tr ("Telefono: ") );
    QLabel* leMail = new QLabel (tr ("eMail : ") );

    QGroupBox* credentialBox = new QGroupBox ( tr ("Credenziali Membro") );
    QGridLayout* crdLayout = new QGridLayout;

    crdLayout->addWidget(lNick, 0 ,0);
    crdLayout->addWidget(nick, 0, 1);

    credentialBox->setLayout(crdLayout);

    QGroupBox* bioBox = new QGroupBox ( tr ("Informazioni personali ") );
    QGridLayout* bioLayout = new QGridLayout;

    /*bioLayout->addWidget(lNick, 0, 0);
    bioLayout->addWidget(nick, 0, 1);*/

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

    //qui mancano tutti gli hobby, gli interessi le esperienze e le amicizie
    QGroupBox* hobbyBox = new QGroupBox ( tr("Hobby") );
    QGridLayout* hobbyLayout = new QGridLayout;

    //...

    hobbyBox->setLayout(hobbyLayout);

    QGroupBox* interestsBox = new QGroupBox ( tr ("Interessi" ) );
    QGridLayout* interestsLayout = new QGridLayout;

    //...

    interestsBox->setLayout(interestsLayout);

    QGroupBox* experiencesBox = new QGroupBox ( tr ("Esperienze") );
    QGridLayout* experiencesLayout = new QGridLayout;

    //...

    experiencesBox->setLayout(experiencesLayout);

    QGroupBox* friendshipsBox = new QGroupBox ( tr ("Amicizie") );
    QGridLayout* friendshipsLayout = new QGridLayout;

    //...

    friendshipsBox->setLayout(friendshipsLayout);

    QVBoxLayout* layoutTot = new QVBoxLayout;

    layoutTot->addWidget(credentialBox);
    layoutTot->addWidget(bioBox);
    layoutTot->addWidget(hobbyBox);
    layoutTot->addWidget(interestsBox);
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

    //E LE AMICIZIE?

}


AdminMWViewerView::~AdminMWViewerView(){

    delete nick;
    delete name;
    delete surname;
    delete birth;
    delete phone;
    delete eMail;

    QVector<QLabel*>::iterator it;

    for (it = hobby.begin(); it != hobby.end(); ++it)
        delete *it;

    for (it = interests.begin(); it != interests.end(); ++it)
        delete *it;

    QVector<labelEvent*>::iterator ite;

    for (ite = experiences.begin(); ite != experiences.end(); ++ite)
        delete *ite;
}

void AdminMWViewerView::setProfile(const QString & pNick,
                                   const QString & pName,
                                   const QString & pSurname,
                                   const QString & pBirth,
                                   const QString & pPhone,
                                   const QString & pEMail,
                                   const QVector<QString> & pHobby,
                                   const QVector<QString> & pInterests,
                                   const QVector<Event> & pExperience,
                                   const QVector<QString> & pFriendships){

    nick->setText(pNick);
    name->setText(pName);
    surname->setText(pSurname);
    birth->setText(pBirth);
    phone->setText(pPhone);
    eMail->setText(pEMail);

    QVector<QString>::const_iterator its;
    for (its = pHobby.cbegin(); its != pHobby.cend(); ++its){

        QLabel* newHobby = new QLabel (*its);

        hobby.push_back(newHobby);
    }
    for (its = pInterests.cbegin(); its != pInterests.cend(); ++its){

        QLabel* newInterests = new QLabel (*its);

        interests.push_back(newInterests);
    }

    QVector<Event>::const_iterator ite;
    for (ite = pExperience.cbegin(); ite != pExperience.cend(); ++ite){

        labelEvent* newEvent = new labelEvent(*ite);

        experiences.push_back(newEvent);
    }

    for (its = pFriendships.cbegin(); its != pFriendships.cend(); ++its){

        QLabel* newFriend = new QLabel (*its);

        friendships.push_back(newFriend);
    }
}


//labelEvent

AdminMWViewerView::labelEvent::labelEvent(const Event & newEvent)
    : begin(new QLabel(newEvent.cgetBegin().toString("dd-MM-yyyy"))),
      end(new QLabel(newEvent.cgetFinish().toString("dd-MM-yyyy"))),
      desc(new QLabel(newEvent.cgetDesc())),
      where(new QLabel(newEvent.cgetWhere()))
{}

AdminMWViewerView::labelEvent::labelEvent(const QString & nBegin,
                                          const QString & nEnd,
                                          const QString & nDesc,
                                          const QString & nWhere)
    : begin(new QLabel(nBegin)),
      end(new QLabel(nEnd)),
      desc(new QLabel(nDesc)),
      where(new QLabel(nWhere))
{}

AdminMWViewerView::labelEvent::~labelEvent(){

    delete begin;
    delete end;
    delete desc;
    delete where;
}

const QLabel* AdminMWViewerView::labelEvent::cgetBegin()const{

    return begin;
}

const QLabel* AdminMWViewerView::labelEvent::cgetEnd()const{

    return end;
}

const QLabel* AdminMWViewerView::labelEvent::cgetDescription()const{

    return desc;
}

const QLabel* AdminMWViewerView::labelEvent::cgetWhere()const{

    return where;
}
