#ifndef ADMINADDMEMBERWC_H
#define ADMINADDMEMBERWC_H

#include <QObject>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>

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
                   const QVector<QString> & = QVector<QString>(),
                   const QVector<Event> & = QVector<Event>());

signals:

    void resumeAdmin(const SmartMember &);

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
