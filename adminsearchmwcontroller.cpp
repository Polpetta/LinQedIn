#include "adminsearchmwcontroller.h"

void AdminSearchMWController::closeView(QCloseEvent * event) const{

    event->accept(); //accetto l'evento della chiusura della finestra

    emit resumeAdmin();
}

AdminSearchMWController::AdminSearchMWController(AdminSearchMWModel* nModel,
                                                 AdminSearchMWView* nView)
    : model (nModel), view (nView), memberDetails(new QSignalMapper)
{


    connect (view,
             SIGNAL (requestClose( QCloseEvent * )),
             this,
             SLOT (closeView( QCloseEvent* )));

    connect (view,
             SIGNAL (newHobbyFilter(const QString &)),
             this,
             SLOT (newHobby(const QString &)));

    connect (view,
             SIGNAL (newInterestsFilter(const QString &)),
             this,
             SLOT (newInterests(const QString &)));

    connect (view,
             SIGNAL (searchConfirm (const QString &,
                                    const QString &,
                                    const QString &)),
             this,
             SLOT (execSearch (const QString &,
                               const QString &,
                               const QString &)));

    connect (memberDetails,
             SIGNAL (mapped(QString)),
             this,
             SLOT (showMemberProfile(const QString &)));

    //ci andranno le varie connect
}

AdminSearchMWController::~AdminSearchMWController()
{

    delete model;
    delete view;

    delete memberDetails;
}

void AdminSearchMWController::showUI()const{

    view->show();
}

void AdminSearchMWController::newHobby(const QString & nHobby) const{

    if (nHobby.size() > 0)
        model->addH(nHobby);
}

void AdminSearchMWController::newInterests(const QString & nInterests) const{

    if (nInterests.size() > 0)
        model->addI(nInterests);
}

void AdminSearchMWController::messageError(const ParserError & err) const{

    QString error;

    if (err == ParserError::bad_date){

        error = tr ("La data non risponde al formato dd-mm-yyyy");

    }else if (err == ParserError::bad_name){

        error = tr ("Il nome può contenere solamente [a-z] o [A-Z] con spazi");

    }else if (err == ParserError::bad_surname){

        error = tr ("Il cognome può contenere solamente [a-z] o [A-Z] con spazi");
    }

    QMessageBox info(QMessageBox::Critical,
                     tr ("Errore nel parsing dei dati"),
                     error,
                     QMessageBox::Ok);

    info.exec();

}

void AdminSearchMWController::execSearch(const QString & sName,
                                         const QString & sSurname,
                                         const QString & sDate) const{

    //pulisco la ricerca precedente
    model->wipeSearchResults();

    QDate data (QDate::fromString(sDate, "dd-MM-yyyy"));

    if (sDate.size() >0 && data.isValid() == false){

        messageError(ParserError::bad_date);
        return;
    }

    QRegularExpression nameRe;
    QRegularExpression surnameRe;

    QString patternName = "([\\w+])*";

    nameRe.setPattern(patternName);
    surnameRe.setPattern(patternName);

    nameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    surnameRe.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch nameMatch = nameRe.match(sName);
    QRegularExpressionMatch surnameMatch = surnameRe.match(sSurname);

    if (nameMatch.hasMatch() == false){

        messageError(ParserError::bad_name);
        return;
    }

    if (surnameMatch.hasMatch() == false){

        messageError(ParserError::bad_surname);
        return;
    }

    const QVector<QString> & sHobby= model->cgetHobby();
    const QVector<QString> & sInterests = model->cgetInterests();

    model->wipeBuffers();

    Personal tmpP (Bio(sName,
                       sSurname,
                       data),
                   sHobby,
                   sInterests);

    Profile toSearch (tmpP);

    emit querySearch(toSearch);

}

void AdminSearchMWController::setSearchResults(const DataMember & result) const{

    model->setSearchResults(result);

    if (result.size() == 0){

        QMessageBox info (QMessageBox::Information,
                          tr ("Ricerca senza risultati" ),
                          tr ("La ricerca non ha prodotto risultati"),
                          QMessageBox::Ok);

        info.exec();
        return;
    }


    TableSearch* tRes = view->getTable();

    tRes->disableOldResult();

    DataMember::const_iterator it;

    for (it = result.cbegin(); it != result.cend(); ++it){

        const QString & nick = (*it)->cgetCredential().getCredential();
        const QString & name = (*it)->cgetProfile().cgetPersonal().cgetBio().getName();
        const QString & surn = (*it)->cgetProfile().cgetPersonal().cgetBio().getSurname();
        const QString & data = (*it)->cgetProfile().cgetPersonal().cgetBio().getBirthday().toString("dd-MM-yyyy");

        tRes->addRow(name,
                     surn,
                     data);

        QPushButton* lastDetail = tRes->getButtonLastItem();

        //bisogna usare QSignalMapper: http://doc.qt.io/qt-5/signalsandslots.html

        memberDetails->setMapping(lastDetail, nick);

        connect (lastDetail,
                 SIGNAL (clicked()),
                 memberDetails,
                 SLOT (map()));

    }

    tRes->addSeparator(); //separatore tra una ricerca e l'altra

}

void AdminSearchMWController::showMemberProfile(const QString & nick)const{

    const SmartMember & member = model->getMemberByNick(nick);

    if (member.cgetPunt() == nullptr){

        QMessageBox info (QMessageBox::Critical,
                          tr ("Impossibile trovare dettagli utente"),
                          tr ("Sembra non sia possibile trovare i"
                              " dettagli per questo utente"));
        info.exec();

    }else{

        //bisogna mandare alla view che costruisca una finestra con le info

        const Bio & bio = member->cgetProfile().cgetPersonal().cgetBio();
        const QVector<QString> & hobby = member->cgetProfile().cgetPersonal().cgetHobby().toVector();
        const QVector<QString> & interests = member->cgetProfile().cgetPersonal().cgetInterests().toVector();

        const QVector<Event> & experiences = member->cgetProfile().cgetExperiences().toVector();

        QVector<QString>* stringExperiences = new QVector<QString>;
        QVector<Event>::const_iterator it;

        for (it = experiences.cbegin(); it != experiences.cend(); ++it){

            stringExperiences->push_back((*it).toString());
        }

        const QVector<QString> & friendships = member->cgetFriendships().toVector();

        AdminMWViewerController* pViewer = model->getProfileViewer();
        pViewer->resetView(); //pulisco la vista se ce ne sono state di precedenti

        pViewer->setProfile(nick,
                            bio.getName(),
                            bio.getSurname(),
                            bio.getBirthday().toString("dd-MM-yyyy"),
                            bio.getPhone(),
                            bio.getMail(),
                            hobby,
                            interests,
                            *stringExperiences,
                            friendships);


    }


}
