#include "adminsearchmwcontroller.h"

void AdminSearchMWController::closeView(QCloseEvent * event) const{

    event->accept(); //accetto l'evento della chiusura della finestra

    emit resumeAdmin();
}

AdminSearchMWController::AdminSearchMWController(AdminSearchMWModel* nModel,
                                                 AdminSearchMWView* nView)
    : model (nModel), view (nView)
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

    //ci andranno le varie connect
}

AdminSearchMWController::~AdminSearchMWController()
{

    delete model;
    delete view;
}

void AdminSearchMWController::showUI()const{

    view->show();
}

void AdminSearchMWController::newHobby(const QString & nHobby) const{

    model->addH(nHobby);
}

void AdminSearchMWController::newInterests(const QString & nInterests) const{

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

    //da implementare
    //Nota: bisogna far visualizzare un avviso se non ci sono stati risultati
    if (result.size() == 0){

        QMessageBox info (QMessageBox::Information,
                          tr ("Ricerca senza risultati" ),
                          tr ("La ricerca non ha prodotto risultati"),
                          QMessageBox::Ok);

        info.exec();
    }
}
