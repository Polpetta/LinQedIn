#ifndef ADMINAMWHOBBY_H
#define ADMINAMWHOBBY_H

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>

class AdminAMWHobby : public QWizardPage
{
public:
    AdminAMWHobby(QWidget* = nullptr);

    ~AdminAMWHobby();

    const QVector<QString> & cgetHobby()const;

private:

    QVector<QString> hobby;
};

#endif // ADMINAMWHOBBY_H
