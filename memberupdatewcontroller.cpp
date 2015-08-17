#include "memberupdatewcontroller.h"

MemberUpdateWController::MemberUpdateWController(const SmartMember & member)
    : model (new MemberUpdateWModel), view (new MemberUpdateWView)
{

    const Bio & bio = member->cgetProfile().cgetPersonal().cgetBio();

    //qui setto la view in base ai dati dell'utente
    view->setBio(bio.getName(),
                 bio.getSurname(),
                 bio.getBirthday().toString("dd-MM-yyyy"),
                 bio.getPhone(),
                 bio.getMail());

    //varie connect
    connect (view,
             SIGNAL (saveBio(const QString &,
                             const QString &,
                             const QString &,
                             const QString &,
                             const QString &)),
             this,
             SLOT (processBio(const QString &,
                              const QString &,
                              const QString &,
                              const QString &,
                              const QString &)));

}

MemberUpdateWController::~MemberUpdateWController(){

    delete model;
    delete view;
}

void MemberUpdateWController::showUI()const{

    view->show();
}

void MemberUpdateWController::processBio(const QString & name,
                                         const QString & surname,
                                         const QString & birthDay,
                                         const QString & phone,
                                         const QString & eMail) const{

    //controlli regex sui dati immessi
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

        qDebug()<<"Pattern Valido";

        QMessageBox info(QMessageBox::Information,
                         tr ("Aggiornamento completato"),
                         tr ("L'aggiornamento delle Bio è<br>"
                             "stato completato con successo") );

        info.exec();


    }
}
