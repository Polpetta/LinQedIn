#ifndef ADMINAMWBIO_H
#define ADMINAMWBIO_H

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>
#include <QVariant>

class AdminAMWBio : public QWizardPage
{
public:
    AdminAMWBio(QWidget* = nullptr);

    ~AdminAMWBio();

    const QString & cgetField(const QString &)const;
};

#endif // ADMINAMWBIO_H
