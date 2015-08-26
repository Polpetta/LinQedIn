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
    Q_OBJECT

signals:

    void newInsert(const QString &);

public slots:

    void emitInsert();

    void addInterests(const QString &);

public:
    AdminAMWInterests(QWidget* = nullptr);

    ~AdminAMWInterests();

    const QVector<QString> & cgetInterests ()const;
    void clear();

private:

    QVector<QString> interests;

    QLineEdit* interestsEdit;
};

#endif // ADMINAMWINTERESTS_H
