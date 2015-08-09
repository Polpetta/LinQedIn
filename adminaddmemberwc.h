#ifndef ADMINADDMEMBERWC_H
#define ADMINADDMEMBERWC_H

#include <QObject>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>

#include <QDebug>

#include "adminaddmemberwm.h"
#include "adminaddmemberwv.h"

class AdminAddMemberWC : public QObject
{
    Q_OBJECT

public slots:

    void addMember(const QString & = QString(),
                   const QString & = QString(),
                   const QString & = QString(),
                   const QString & = QString(),
                   const QString & = QString(),
                   const QString & = QString(),
                   const QString & = QString(),
                   const QVector<QString> & = QVector<QString>(),
                   const QVector<QString> & = QVector<QString>());

signals:

    void resumeAdmin(const SmartMember & = nullptr);

public:
    AdminAddMemberWC(AdminAddMemberWM* = new AdminAddMemberWM,
                     AdminAddMemberWV* = new AdminAddMemberWV);

    ~AdminAddMemberWC();

    void showUI();

private:

    AdminAddMemberWM* model;
    AdminAddMemberWV* view;
};

#endif // ADMINADDMEMBERWC_H
