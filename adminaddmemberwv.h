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

#include "adminamwintro.h"
#include "adminamwbio.h"
#include "adminamwhobby.h"
#include "adminamwinterests.h"
#include "adminamwend.h"

class AdminAddMemberWV : public QWizard
{
    Q_OBJECT

public:
    AdminAddMemberWV(QWidget* = nullptr);

    ~AdminAddMemberWV();
};

#endif // ADMINADDMEMBERWV_H
