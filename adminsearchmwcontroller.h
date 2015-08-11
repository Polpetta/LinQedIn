#ifndef ADMINSEARCHMWCONTROLLER_H
#define ADMINSEARCHMWCONTROLLER_H


#include <QObject>
#include <QCloseEvent>

#include "adminsearchmwmodel.h"
#include "adminsearchmwview.h"

class AdminSearchMWController : public QObject
{
    Q_OBJECT

public:
    AdminSearchMWController(AdminSearchMWModel* = new AdminSearchMWModel,
                            AdminSearchMWView* = new AdminSearchMWView);

    ~AdminSearchMWController();

    void showUI()const;

signals:

    void resumeAdmin()const;

public slots:

    void closeView( QCloseEvent* )const;

private:

    AdminSearchMWModel* model;
    AdminSearchMWView* view;
};

#endif // ADMINSEARCHMWCONTROLLER_H
