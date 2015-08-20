#include "membersearchmwcontroller.h"

MemberSearchMWController::MemberSearchMWController(const QString & type)
    : model(new MemberSearchMWModel(type)),
      view (new MemberSearchMWView),
      memberDetails(new QSignalMapper)
{

    if ( type == "Basic"){
        view->blockBio();
        view->blockHobby();
        view->blockInterests();

        view->setNote(tr("I membri di tipo <i>Basic</i> e"
                         " <i>Executive</i> possiedono funzionalità"
                         " aggiuntive"));
    }else if ( type == "Business"){

        view->blockInterests();

        view->setNote(tr("I membri di tipo <i>Executive</i>"
                         " possiedono funzionalità aggiuntive"));
    }

    connect (view,
             SIGNAL (requestClose( QCloseEvent *)),
             this,
             SLOT (closeView( QCloseEvent* )));

    connect (view,
             SIGNAL (emitNewHobby(const QString &)),
             this,
             SLOT (newHobby(const QString &)));

    connect (view,
             SIGNAL (emitNewInterests (const QString &)),
             this,
             SLOT (newInterests(const QString &)));

    connect (view,
             SIGNAL (searchConfirm(const QString &,
                                   const QString &,
                                   const QString &)),
             this,
             SLOT (search(const QString &,
                          const QString &,
                          const QString &)));
}

MemberSearchMWController::~MemberSearchMWController(){

    delete model;
    delete view;

    delete memberDetails;
}

void MemberSearchMWController::newHobby(const QString & nHobby) const{

    if (nHobby.size() > 0)
        model->addH(nHobby);
}

void MemberSearchMWController::newInterests(const QString & nInterests) const{

    if (nInterests.size() > 0)
        model->addI(nInterests);
}

void MemberSearchMWController::showUI()const{

    view->show();
}

void MemberSearchMWController::closeView(QCloseEvent *event) const{

    event->accept();

    emit resumePanel();
}

void MemberSearchMWController::setSearchResults(const DataMember &result) const{

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

void MemberSearchMWController::messageError(const ParserError & err) const{

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

void MemberSearchMWController::search(const QString &sName,
                                      const QString &sSurname,
                                      const QString &sDate) const{

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

    Personal tmpP;

    if (model->cgetType() != "Basic"){
        const QVector<QString> & sHobby= model->cgetHobby();
        const QVector<QString> & sInterests = model->cgetInterests();

        tmpP.setBio(Bio(sName,
                       sSurname,
                       data));

        tmpP.setHobby(sHobby);
        tmpP.setInterests(sInterests);

        /*
         * Solo membri business o executive o successivi possono
         * vedere gli interessi/hobby
         */

    }else{

        tmpP.setBio(Bio(sName,
                         sSurname,
                         data));
    }

    model->wipeBuffers();

    Profile toSearch (tmpP);

    emit querySearch(toSearch);
}
