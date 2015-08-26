#ifndef ADMINCHANGETYPEWCONTROLLER_H
#define ADMINCHANGETYPEWCONTROLLER_H

#include <QObject>
#include <QCloseEvent>
#include <QMessageBox>

#include "adminchangetypewmodel.h"
#include "adminchangetypewview.h"

class AdminChangeTypeWController : public QObject
{
    Q_OBJECT

signals:

    void resumeAdmin()const;

    void confirmChange(const QString &,const QString &)const;

private slots:

    void change(const QString &, const QString &)const;

    void closeView (QCloseEvent* )const;

public:
    AdminChangeTypeWController(AdminChangeTypeWModel* = new AdminChangeTypeWModel,
                               AdminChangeTypeWView* = new AdminChangeTypeWView);

    ~AdminChangeTypeWController();

    void showUI()const;

private:

    AdminChangeTypeWModel* model;
    AdminChangeTypeWView* view;
};

#endif // ADMINCHANGETYPEWCONTROLLER_H
