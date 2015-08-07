#ifndef ADMINADDMEMBERWV_H
#define ADMINADDMEMBERWV_H

#include <QWidget>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>

#include "adminamwintro.h"
#include "adminamwbio.h"
#include "adminamwhobby.h"
#include "adminamwinterests.h"
#include "adminamwend.h"

class AdminAddMemberWV : public QWizard
{
    Q_OBJECT

signals:

    void endAdd(const QString & = QString(),
                const QString & = QString(),
                const QString & = QString(),
                const QString & = QString(),
                const QString & = QString(),
                const QString & = QString(),
                const QString & = QString());

private slots:

    void processItems();

public:
    AdminAddMemberWV(QWidget* = nullptr);

    ~AdminAddMemberWV();

private:

    AdminAMWIntro* intro;
    AdminAMWBio* bio;
    AdminAMWHobby* hobby;
    AdminAMWInterests* interests;
    AdminAMWEnd* end;

};

#endif // ADMINADDMEMBERWV_H
