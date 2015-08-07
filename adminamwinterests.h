#ifndef ADMINAMWINTERESTS_H
#define ADMINAMWINTERESTS_H

#include <QWizardPage>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QVector>

class AdminAMWInterests : public QWizardPage
{
public:
    AdminAMWInterests(QWidget* = nullptr);

    ~AdminAMWInterests();

    const QVector<QString> & cgetInterests ()const;

private:

    QVector<QString> interests;
};

#endif // ADMINAMWINTERESTS_H
