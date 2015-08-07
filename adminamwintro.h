#ifndef ADMINAMWINTRO_H
#define ADMINAMWINTRO_H

#include <QWizardPage>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>

class AdminAMWIntro : public QWizardPage
{
public:
    AdminAMWIntro(QWidget* = nullptr);

    ~AdminAMWIntro();

    const QString & cgetType()const;
};

#endif // ADMINAMWINTRO_H
