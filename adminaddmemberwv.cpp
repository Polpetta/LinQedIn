#include "adminaddmemberwv.h"

void AdminAddMemberWV::processItems(){

    const QString & type = intro->cgetType();

    const QString & nick = bio->cgetField("nick");
    const QString & name = bio->cgetField("name");
    const QString & surname = bio->cgetField("surname");
    const QString & birthDay = bio->cgetField("birthDay");
    const QString & phone = bio->cgetField("phone");
    const QString & eMail = bio->cgetField("eMail");

    qDebug()<<"Ottenuto da Intro:";
    qDebug()<<"type: "<<type;

    qDebug()<<"Ottenuto da Bio:";
    qDebug()<<"nick: "<<nick;
    qDebug()<<"name: "<<name;
    qDebug()<<"surname: "<<surname;
    qDebug()<<"birthDay: "<<birthDay;
    qDebug()<<"phone: "<<phone;
    qDebug()<<"eMail: "<<eMail;

    const QVector<QString> & hobbyList = hobby->cgetHobby();
    qDebug()<<"Ho ottenuto anche gli Hobby";

    emit endAdd(type,
                nick,
                name,
                surname,
                birthDay,
                phone,
                eMail,
                hobbyList);
}

AdminAddMemberWV::AdminAddMemberWV(QWidget * parent)
    : QWizard(parent), intro (new AdminAMWIntro), bio (new AdminAMWBio), hobby (new AdminAMWHobby), interests (new AdminAMWInterests), end (new AdminAMWEnd)
{

    /*AdminAMWIntro* intro = new AdminAMWIntro;
    AdminAMWBio* bio = new AdminAMWBio;
    AdminAMWHobby* hobby = new AdminAMWHobby;
    AdminAMWInterests* interests = new AdminAMWInterests;
    AdminAMWEnd* end = new AdminAMWEnd; */

    addPage(intro);
    addPage(bio);
    addPage(hobby);
    addPage(interests);
    addPage(end);

    setWindowTitle( tr("Wizard Aggiunta Iscritto") );

    /*const QString & nick = bio->cgetField("nick");
    const QString & name = bio->cgetField("name");
    const QString & surname = bio->cgetField("surname");
    const QString & birthDay = bio->cgetField("birthDay");
    const QString & phone = bio->cgetField("phone");
    const QString & eMail = bio->cgetField("eMail");

    qDebug()<<"Ottenuto da Bio:";
    qDebug()<<"nick: "<<nick;
    qDebug()<<"name: "<<name;
    qDebug()<<"surname: "<<surname;
    qDebug()<<"birthDay: "<<birthDay;
    qDebug()<<"phone: "<<phone;
    qDebug()<<"eMail: "<<eMail;*/

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
    delete end;

}
