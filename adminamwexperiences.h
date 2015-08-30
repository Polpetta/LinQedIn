#ifndef ADMINAMWEXPERIENCES_H
#define ADMINAMWEXPERIENCES_H


#include <QWizardPage>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QVector>
#include <QMessageBox>

#include "event.h"

class AdminAMWExperiences : public QWizardPage
{
    Q_OBJECT

signals:

    void newEvent(const Event &);

private slots:

    void emitEvent();

    void addExperiences(const Event &);

public:
    AdminAMWExperiences(QWidget* = nullptr);

    ~AdminAMWExperiences();

    const QVector<Event> & cgetExperiences ()const;
    void clear();

private:

    QVector<Event> experiences;

    QLineEdit* beginEdit;
    QLineEdit* finishEdit;
    QLineEdit* descEdit;
    QLineEdit* whereEdit;
};

#endif // ADMINAMWEXPERIENCES_H
