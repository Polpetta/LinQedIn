#ifndef ADMINSEARCHMWCONTROLLER_H
#define ADMINSEARCHMWCONTROLLER_H


#include <QObject>
#include <QCloseEvent>

#include <QDate>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>

#include "adminsearchmwmodel.h"
#include "adminsearchmwview.h"
#include "datamember.h"

#include "profile.h"

class AdminSearchMWController : public QObject
{
    Q_OBJECT

public:
    AdminSearchMWController(AdminSearchMWModel* = new AdminSearchMWModel,
                            AdminSearchMWView* = new AdminSearchMWView);

    ~AdminSearchMWController();

    void showUI()const;

    void setSearchResults(const DataMember &)const;

signals:

    void resumeAdmin()const;
    void querySearch(const Profile &)const;

public slots:

    void closeView( QCloseEvent* )const;

    void newHobby(const QString &)const;
    void newInterests(const QString &)const;

    void execSearch(const QString &,
                    const QString &,
                    const QString &)const;

private:

    enum ParserError{
        bad_date = 0,
        bad_name = 1,
        bad_surname = 2
    };

    void messageError (const ParserError &)const;

    AdminSearchMWModel* model;
    AdminSearchMWView* view;
};

#endif // ADMINSEARCHMWCONTROLLER_H
