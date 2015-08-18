#ifndef MEMBERUPDATEWCONTROLLER_H
#define MEMBERUPDATEWCONTROLLER_H

#include <QObject>

#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QMessageBox>

#include <QDebug>

#include "memberupdatewmodel.h"
#include "memberupdatewview.h"

#include "smartmember.h"
#include "bio.h"
#include "memberexecutive.h"

class MemberUpdateWController : public QObject
{
    Q_OBJECT

signals:

    void resumePanel()const;

    void updateBioInfo(const Bio &)const;

    void insertHobby(const QString &)const;
    void removeHobby(const QString &)const;

private slots:

    void processBio(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &)const;

    void processAddHobby(const QString &)const;
    void processRmHobby(const QString &)const;

public slots:

    void closeView( QCloseEvent *)const;

public:
    MemberUpdateWController(const SmartMember &);

    ~MemberUpdateWController();

    void showUI()const;

private:

    MemberUpdateWModel* model;
    MemberUpdateWView* view;
};

#endif // MEMBERUPDATEWCONTROLLER_H
