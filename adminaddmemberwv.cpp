#include "adminaddmemberwv.h"

void AdminAddMemberWV::processItems(){

    const QString & type = intro->cgetType();

    const QString & nick = bio->cgetField("nick");
    const QString & name = bio->cgetField("name");
    const QString & surname = bio->cgetField("surname");
    const QString & birthDay = bio->cgetField("birthDay");
    const QString & phone = bio->cgetField("phone");
    const QString & eMail = bio->cgetField("eMail");


    const QVector<QString> & hobbyList = hobby->cgetHobby();
    hobby->clear();

    const QVector<QString> & interestsList = interests->cgetInterests();
    interests->clear();

    const QVector<Event> & experiencesList = experiences->cgetExperiences();
    experiences->clear();

    emit endAdd(type,
                nick,
                name,
                surname,
                birthDay,
                phone,
                eMail,
                hobbyList,
                interestsList,
                experiencesList);
}

AdminAddMemberWV::AdminAddMemberWV(QWidget * parent)
    : QWizard(parent),
      intro (new AdminAMWIntro),
      bio (new AdminAMWBio),
      hobby (new AdminAMWHobby),
      interests (new AdminAMWInterests),
      experiences(new AdminAMWExperiences),
      end (new AdminAMWEnd)
{

    addPage(intro);
    addPage(bio);
    addPage(hobby);
    addPage(interests);
    addPage(experiences);
    addPage(end);

    setWindowTitle( tr("Wizard Aggiunta Iscritto") );

    setFixedSize( sizeHint() );

    /*
     * Devo passare gli argomenti ottenuti a chi se ne occuperà
     * dopo attraverso la signal
     */

    connect (this,
             SIGNAL (accepted()),
             this,
             SLOT (processItems()));

    connect (this,
             SIGNAL (rejected()),
             this,
             SIGNAL (endAdd()));


}

AdminAddMemberWV::~AdminAddMemberWV(){

    delete intro;
    delete bio;
    delete hobby;
    delete interests;
    delete experiences;
    delete end;

}
