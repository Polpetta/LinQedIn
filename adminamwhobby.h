#ifndef ADMINAMWHOBBY_H
#define ADMINAMWHOBBY_H

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QWidget>

#include <QDebug>

class AdminAMWHobby : public QWizardPage
{
    Q_OBJECT

signals:

    void newInsert (const QString &);

public slots:

    void emitInsert();

    void addHobby(const QString &);

public:
    AdminAMWHobby(QWidget* = nullptr);

    ~AdminAMWHobby();

    const QVector<QString> & cgetHobby();

private:

    QVector<QString> hobby;

    QLineEdit* hobbyEdit;
};

#endif // ADMINAMWHOBBY_H
