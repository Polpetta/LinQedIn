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

    QString getField(const QString &)const;
};

#endif // ADMINAMWBIO_H
