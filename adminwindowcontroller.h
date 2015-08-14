#ifndef ADMINWINDOWCONTROLLER_H
#define ADMINWINDOWCONTROLLER_H

#include <QObject>
#include <QMessageBox>

#include <QDebug>

#include "admin.h"
#include "smartadmin.h"
#include "memberexecutive.h"
#include "datamember.h"

#include "adminwindowmodel.h"
#include "adminwindowview.h"

class AdminWindowController : public QObject
{

    Q_OBJECT

private slots:
    void execAddMember()const;
    void execSearchMember();
    void execRmMember();
    void execChangeMember();
    void execSaveDb();

    void addMember(const SmartMember &)const;
    void SearchMember(const Profile &)const;
    void rmMember(const QString &)const;
    void changeMember(const QString &, const QString &)const;

public slots:
    void showUI() const;

public:
    AdminWindowController(AdminWindowModel* = new AdminWindowModel,
                          AdminWindowView* = new AdminWindowView);

    virtual ~AdminWindowController();

private:

    AdminWindowModel* model;
    AdminWindowView* view;

};

#endif // ADMINWINDOWCONTROLLER_H
