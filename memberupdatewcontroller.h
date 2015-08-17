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

private slots:

    void processBio(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &)const;

public:
    MemberUpdateWController(const SmartMember &);

    ~MemberUpdateWController();

    void showUI()const;

private:

    MemberUpdateWModel* model;
    MemberUpdateWView* view;
};

#endif // MEMBERUPDATEWCONTROLLER_H
