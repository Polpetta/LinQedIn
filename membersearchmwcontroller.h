#ifndef MEMBERSEARCHMWCONTROLLER_H
#define MEMBERSEARCHMWCONTROLLER_H

#include <QObject>
#include <QCloseEvent>
#include <QSignalMapper>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include "membersearchmwmodel.h"

#include "viewerpair.h"
#include "smartmember.h"
#include "member.h"
#include "profile.h"
#include "personal.h"
#include "datamember.h"

class MemberSearchMWController : public QObject
{
    Q_OBJECT

signals:

    void resumePanel()const;

    void querySearch(const Profile &)const;

private slots:

    void closeView( QCloseEvent *)const;

    void newHobby(const QString &)const;
    void newInterests(const QString &)const;

    void search(const QString &,
                const QString &,
                const QString &)const;

    void showMemberProfile(const QString &)const;

public:
    MemberSearchMWController(viewCollection *);

    ~MemberSearchMWController();

    void showUI()const;

    void setSearchResults(const DataMember &)const;

private:

    enum ParserError{
        bad_date = 0,
        bad_name = 1,
        bad_surname = 2
    };

    void messageError (const ParserError &)const;

    MemberSearchMWModel* model;
    MSearchView* view;

    QSignalMapper* memberDetails;
};

#endif // MEMBERSEARCHMWCONTROLLER_H
