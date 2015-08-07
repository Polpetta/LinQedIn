#ifndef ADMINWINDOWCONTROLLER_H
#define ADMINWINDOWCONTROLLER_H

#include <QObject>
#include <QMessageBox>

#include "admin.h"
#include "smartadmin.h"
#include "memberexecutive.h"
#include "datamember.h"

#include "adminwindowmodel.h"
#include "adminwindowview.h"

class AdminWindowController : public QObject
{

    Q_OBJECT

public slots:

    void execAddMember();
    void execSearchMember();
    void execRmMember();
    void execChangeMember();
    void execSaveDb();
    void showUI() const;
    void addMember(const SmartMember &)const;



public:
    AdminWindowController(AdminWindowModel* = new AdminWindowModel,
                          AdminWindowView* = new AdminWindowView);

    virtual ~AdminWindowController();

private:


    AdminWindowModel* model;
    AdminWindowView* view;

};

#endif // ADMINWINDOWCONTROLLER_H
