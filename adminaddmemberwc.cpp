#include "adminaddmemberwc.h"

void AdminAddMemberWC::addMember(const QString & type,
                                 const QString & nick,
                                 const QString & name,
                                 const QString & surname,
                                 const QString & birthDay,
                                 const QString & phone,
                                 const QString & eMail,
                                 const QVector<QString> & nHobby,
                                 const QVector<QString> & nInterests,
                                 const QVector<Event> & nExperiences){

    //bisogna fare il check dei dati in arrivo prima di ciò
    SmartMember newMember;

    Hobby hobby = nHobby;
    Interests interests = nInterests;
    Experiences experiences = nExperiences;

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

        Personal newPersonal (Bio(name,
                                  surname,
                                  birth,
                                  phone,
                                  eMail),
                              hobby,
                              interests);

        Profile newProfile (newPersonal,
                            experiences);

        if (type == "Basic")
            newMember = new MemberBasic (Credentials(nick),
                                        type,
                                         newProfile
                                         );
        else if (type == "Business")
            newMember = new MemberBusiness (Credentials(nick),
                                            type,
                                            newProfile
                                            );
        else if (type == "Executive"){
            newMember = new MemberExecutive (Credentials(nick),
                                             type,
                                             newProfile
                                              );
        }
    }

    if (newMember.cgetPunt() == nullptr){

        QMessageBox info (QMessageBox::Warning,
                          tr ("Errore creazione Membro"),
                          tr ("Controllare i dati immessi. <br><b>Nota</b>: gli"
                              " indirizzi email non possono contenere punti o "
                              "spazi nella loro prima parte."),
                          QMessageBox::Ok);

        info.exec();
    }

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
                            const QString &,
                            const QVector<QString> &,
                            const QVector<QString> &,
                            const QVector<Event> &)),
             this,
             SLOT (addMember(const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QVector<QString> &,
                             const QVector<QString> &,
                             const QVector<Event> &)));

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
