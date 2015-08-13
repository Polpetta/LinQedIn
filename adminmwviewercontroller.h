#ifndef ADMINMWVIEWERCONTROLLER_H
#define ADMINMWVIEWERCONTROLLER_H

#include <QObject>

#include "adminmwviewermodel.h"
#include "adminmwviewerview.h"

class AdminMWViewerController : public QObject
{
    Q_OBJECT

public:
    AdminMWViewerController(AdminMWViewerModel* = new AdminMWViewerModel,
                            AdminMWViewerView* = new AdminMWViewerView);

    ~AdminMWViewerController();

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString> &,
                    const QVector<QString> &,
                    const QVector<Event> &,
                    const QVector<QString> &)const;

private:

    AdminMWViewerModel* model;
    AdminMWViewerView* view;
};

#endif // ADMINMWVIEWERCONTROLLER_H
