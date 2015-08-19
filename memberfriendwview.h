#ifndef MEMBERFRIENDWVIEW_H
#define MEMBERFRIENDWVIEW_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QMessageBox>

#include "listviewer.h"


class MemberFriendWView : public QWidget
{
    Q_OBJECT

signals:

    void requestClose (QCloseEvent* );

    void execAddFriend(const QString &)const;
    void execRmFriend(const QString &)const;

private slots:

    void emitNewFriend()const;
    void emitRmFriend()const;

public:
    MemberFriendWView(QWidget* = nullptr);

    ~MemberFriendWView();

    listViewer* getFriendshipsList()const;

protected:

    void closeEvent ( QCloseEvent* );

private:

    QLineEdit* modifyFriend;
    listViewer* friendships;
};

#endif // MEMBERFRIENDWVIEW_H
