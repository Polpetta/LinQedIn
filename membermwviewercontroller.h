#ifndef MEMBERMWVIEWERCONTROLLER_H
#define MEMBERMWVIEWERCONTROLLER_H

#include <QObject>

#include <QDebug>

#include "membermwviewermodel.h"
#include "mviewerviewexecutive.h"

class MemberMWViewerController : public QObject
{
    Q_OBJECT

public:
    MemberMWViewerController(MViewerView*);

    ~MemberMWViewerController();

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString>&,
                    const QVector<QString>&,
                    const QVector<QString>&,
                    const QVector<QString>&)const;

    void resetView();

public slots:

    void showUI()const;

private:

    MemberMWViewerModel* model;
    MViewerView* view;
};

#endif // MEMBERMWVIEWERCONTROLLER_H
