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

    listViewer* hobby = view->getHobbyList();

    Hobby::const_iterator ith;

    const Hobby & hbbMember = member->cgetProfile().cgetPersonal().cgetHobby();

    for ( ith = hbbMember.cbegin(); ith != hbbMember.cend(); ++ith){

        hobby->addLabel(*ith);
    }


    listViewer* interests = view->getInterestsList();

    Interests::const_iterator iti;

    const Interests & itiMember = member->cgetProfile().cgetPersonal().cgetInterests();

    for ( iti = itiMember.cbegin(); iti != itiMember.cend(); ++iti){

        interests->addLabel(*iti);
    }


    listViewer* experiences = view->getExperiencesList();

    Experiences::const_iterator ite;

    const Experiences & iteMember = member->cgetProfile().cgetExperiences();

    for (ite = iteMember.cbegin(); ite != iteMember.cend(); ++ite){

        experiences->addLabel((*ite).toString());
    }

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

    connect (view,
             SIGNAL (requestClose (QCloseEvent* ) ),
             this,
             SLOT (closeView( QCloseEvent* )));

    connect (view,
             SIGNAL (execAddHobby(const QString &)),
             this,
             SLOT (processAddHobby(const QString &)));

    connect (view,
             SIGNAL (execRmHobby(const QString &)),
             this,
             SLOT (processRmHobby(const QString &)));

    connect (view,
             SIGNAL (execAddInterests(const QString &)),
             this,
             SLOT (processAddInterests(const QString &)));

    connect (view,
             SIGNAL (execRmInterests(const QString &)),
             this,
             SLOT (processRmInterests(const QString &)));

    connect(view,
            SIGNAL (execAddExperiences(const QString &,
                                       const QString &,
                                       const QString &,
                                       const QString &)),
            this,
            SLOT (processAddExperience(const QString &,
                                       const QString &,
                                       const QString &,
                                       const QString &)));

    connect(view,
            SIGNAL (execRmExperiences(const QString &,
                                      const QString &,
                                      const QString &,
                                      const QString &)),
            this,
            SLOT (processRmExperience(const QString &,
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

        QMessageBox info(QMessageBox::Information,
                         tr ("Aggiornamento completato"),
                         tr ("L'aggiornamento delle Bio è<br>"
                             "stato completato con successo") );

        info.exec();

        emit updateBioInfo(Bio(name,
                               surname,
                               birth,
                               phone,
                               eMail));


    }
}

void MemberUpdateWController::closeView(QCloseEvent *event) const{

    event->accept(); //accetto chiusura finestra

    emit resumePanel();
}

void MemberUpdateWController::processAddHobby(const QString & newHobby)const{

    if (newHobby.size() > 0){

        view->getHobbyList()->addLabel(newHobby);
        emit insertHobby(newHobby);
    }else{

        QMessageBox info(QMessageBox::Warning,
                         tr ("Hobby non valido"),
                         tr ("È necessario inserire un hobby valido"));

        info.exec();
    }
}

void MemberUpdateWController::processRmHobby(const QString & target) const{

    if (target.size() > 0){

        view->getHobbyList()->changeLabel(target, "<s>"+target+"</s>");
        emit removeHobby(target);
    }else{

        QMessageBox info(QMessageBox::Warning,
                         tr ("Rimozione non possibile"),
                         tr ("L'hobby inserito non è valido"));

        info.exec();
    }
}

void MemberUpdateWController::processAddInterests(const QString & newInt) const{

    if (newInt.size() > 0){

        view->getInterestsList()->addLabel(newInt);
        emit insertInterests(newInt);
    }else{

        QMessageBox info(QMessageBox::Warning,
                         tr ("Interesse non valido"),
                         tr ("L'interesse inserito non è valido"));

        info.exec();
    }
}

void MemberUpdateWController::processRmInterests(const QString &target) const{

    if (target.size() > 0){

        view->getInterestsList()->changeLabel(target, "<s>"+target+"</s>");
        emit removeInterests(target);
    }else{

        QMessageBox info(QMessageBox::Warning,
                         tr ("Rimozione non possibile"),
                         tr ("L'iteresse inserito non è valido"));

        info.exec();
    }
}

void MemberUpdateWController::processAddExperience(const QString &start,
                                                   const QString &finish,
                                                   const QString &desc,
                                                   const QString &where)const{

    Event* newEvent = new Event(start,
                                finish,
                                desc,
                                where,
                                "dd-MM-yyyy");

    if (newEvent->isValid()){
        view->getExperiencesList()->addLabel(newEvent->toString());
        emit insertExperience(*newEvent);
        //da controllare e emettere per aggiunta
    }else{

        QMessageBox info(QMessageBox::Warning,
                         tr ("Esperienza non valida"),
                         tr ("L'esperienza inserita non è valida"));

        info.exec();

    }
}

void MemberUpdateWController::processRmExperience(const QString &start,
                                                  const QString &finish,
                                                  const QString &desc,
                                                  const QString &where)const{

    Event* newEvent = new Event(start,
                                finish,
                                desc,
                                where,
                                "dd-MM-yyyy");

    if (newEvent->isValid()){
        view->getExperiencesList()->changeLabel(newEvent->toString(), "<s>"+newEvent->toString()+"</s>");
        emit removeExperience(*newEvent);
        //da controllare e emettere per rimozione
    }else{

        QMessageBox info(QMessageBox::Warning,
                         tr ("Rimozione non possibile"),
                         tr ("L'esperienza inserita non è valida"));

        info.exec();
    }
}
