#ifndef MEMBERMWVIEWERCONTROLLER_H
#define MEMBERMWVIEWERCONTROLLER_H

#include <QObject>

#include <QDebug>

#include "membermwviewermodel.h"
#include "membermwviewerview.h"

class MemberMWViewerController : public QObject
{
    Q_OBJECT

public:
    MemberMWViewerController(MemberMWViewerModel* = new MemberMWViewerModel);

    ~MemberMWViewerController();

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString> &)const; //solo bio + amicizie

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString>&,
                    const QVector<QString>&,
                    const QVector<QString>&)const; //hobby + interests

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString>&,
                    const QVector<QString>&,
                    const QVector<QString>&,
                    const QVector<QString>&)const; //tutto

    void resetView();

public slots:

    void showUI()const;

private:

    MemberMWViewerModel* model;
    MemberMWViewerView* view;
};

#endif // MEMBERMWVIEWERCONTROLLER_H
