#include "adminaddmemberwc.h"

void AdminAddMemberWC::addMember(const QString & type,
                                 const QString & nick,
                                 const QString & name,
                                 const QString & surname,
                                 const QString & birthDay,
                                 const QString & phone,
                                 const QString & eMail){

    //bisogna fare il check dei dati in arrivo prima di ciò
    SmartMember newMember;

    QDate birth (QDate::fromString(birthDay, "dd-MM-yyyy"));

    QRegularExpression nameRe;
    QRegularExpression surnameRe;
    QRegularExpression phoneRe;
    QRegularExpression eMailRe;

    QString patternName = "([\\w+])*";
    QString patternPhone = "([\\d])*";
    QString patternMail = "([\\w+])(@)([\\w+])(.)([\\w+])";

    nameRe.setPattern(patternName);
    surnameRe.setPattern(patternName);
    phoneRe.setPattern(patternPhone);
    eMailRe.setPattern(patternMail);

    nameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    surnameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    eMailRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch nameMatch = nameRe.match(name);
    QRegularExpressionMatch surnameMatch = surnameRe.match(surname);
    QRegularExpressionMatch phoneMatch = phoneRe.match(phone);
    QRegularExpressionMatch eMailMatch = eMailRe.match(eMail);

    bool okName = nameMatch.hasMatch();
    bool okSurname = surnameMatch.hasMatch();
    bool okPhone = phoneMatch.hasMatch();
    bool okMail = eMailMatch.hasMatch();

    if (okMail == false && eMail.size() == 0)
        okMail = true;


    if (okName && okSurname && okPhone && okMail && birth.isValid()){

        /*
         * Creo i vari sottoggetti
         * --MANCA DA INTEGRARE HOBBY E INTERESTS--
         * --DA AGGIUNGERE EXPERIENCES--
         */

        Personal newPersonal (Bio(name,
                                  surname,
                                  birth,
                                  phone,
                                  eMail)
                              //mancano gli hobby
                              //mancano gli interests
                              );

        if (type == "Basic")
            newMember = new MemberBasic (Credentials(nick),
                                        type,
                                         newPersonal
                                         //mancano le Esp
                                         );
        else if (type == "Business")
            newMember = new MemberBusiness (Credentials(nick),
                                            type,
                                            newPersonal
                                            //mancano le Esp
                                            );
        else if (type == "Executive")
            newMember == new MemberExecutive (Credentials(nick),
                                              type,
                                              newPersonal
                                              //mancano le Esp
                                              );
    }
    /*
     * Importante: generare QMessageBox in base all'errore per informare
     * l'utente
     */

   qDebug()<<"Signal di aggiunta utente arrivato";
   qDebug()<<"Ottenuto da signal:";
   qDebug()<<"type: "<<type;
   qDebug()<<"nick: "<<nick;
   qDebug()<<"name: "<<name;
   qDebug()<<"surname: "<<surname;
   qDebug()<<"birthDay: "<<birthDay;
   qDebug()<<"phone: "<<phone;
   qDebug()<<"eMail: "<<eMail;

   emit resumeAdmin(newMember);
}

AdminAddMemberWC::AdminAddMemberWC(AdminAddMemberWM* nModel,
                                   AdminAddMemberWV* nView)
    : model (nModel), view (nView)
{

    connect (view,
             SIGNAL (endAdd(const QString &,
                            const QString &,
                            const QString &,
                            const QString &,
                            const QString &,
                            const QString &,
                            const QString &)),
             this,
             SLOT (addMember(const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &)));


    //verranno create le varie connessioni

}

AdminAddMemberWC::~AdminAddMemberWC()
{

    delete model;
    delete view;
}

void AdminAddMemberWC::showUI(){

    view->show();
    view->restart();
}
