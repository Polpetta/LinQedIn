#ifndef MEMBERFRIENDWCONTROLLER_H
#define MEMBERFRIENDWCONTROLLER_H

#include <QObject>
#include <QCloseEvent>
#include <QMessageBox>

#include "listviewer.h"
#include "memberfriendwmodel.h"
#include "memberfriendwview.h"

#include "smartmember.h"

#include "member.h"


class MemberFriendWController : public QObject
{
    Q_OBJECT

signals:

    void resumePanel()const;

    void confirmAddFriend(const QString &)const;
    void confirmRmFriend(const QString &)const;

private slots:

    void closeView(QCloseEvent *)const;

    void addFriend(const QString &)const;
    void rmFriend(const QString &)const;

public slots:

    void showUI()const;

public:
    MemberFriendWController(const SmartMember &);

    ~MemberFriendWController();

private:

    MemberFriendWModel* model;
    MemberFriendWView* view;
};

#endif // MEMBERFRIENDWCONTROLLER_H
