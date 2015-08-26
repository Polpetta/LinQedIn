#include "adminchangetypewcontroller.h"

void AdminChangeTypeWController::showUI()const{

    view->show();
}

AdminChangeTypeWController::AdminChangeTypeWController(AdminChangeTypeWModel* nModel,
                                                       AdminChangeTypeWView* nView)
    : model (nModel), view (nView)
{
    connect (view,
             SIGNAL (requestClose ( QCloseEvent *) ),
             this,
             SLOT (closeView(QCloseEvent* )));

    connect (view,
             SIGNAL (changeType(const QString &, const QString &)),
             this,
             SLOT (change(const QString &, const QString &)));
}

AdminChangeTypeWController::~AdminChangeTypeWController(){

    delete model;
    delete view;
}

void AdminChangeTypeWController::closeView(QCloseEvent * event) const{

    event->accept();

    emit resumeAdmin();
}

void AdminChangeTypeWController::change(const QString &nick,
                                        const QString &type) const{

    if (nick.size() == 0){

        QMessageBox info(QMessageBox::Warning,
                         tr ("Nickname mancante"),
                         tr ("Per favore inserire un nickname valido") );

        info.exec();
        return;
    }

    if (type.size() == 0){

        QMessageBox info(QMessageBox::Warning,
                         tr ("Nuovo tipo mancante"),
                         tr ("Per favore inserire un tipo per la conversione") );

        info.exec();
        return;
    }

    if (type != "Basic" &&
            type != "Business" &&
            type != "Executive"){

        QMessageBox info(QMessageBox::Warning,
                         tr ("Nuovo tipo invalido"),
                         tr ("Per favore inserire un tipo valido"
                             " per la conversione") );

        info.exec();

        return;

    }

    emit confirmChange (nick, type);
}
