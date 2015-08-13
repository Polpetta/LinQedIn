#ifndef ADMINMWVIEWERVIEW_H
#define ADMINMWVIEWERVIEW_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QGroupBox>
#include <QVBoxLayout>

#include <QVector>
#include "event.h"

class AdminMWViewerView : public QWidget
{
    Q_OBJECT

public:
    AdminMWViewerView(QWidget* = nullptr);

    ~AdminMWViewerView();

public slots:
    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString> &,
                    const QVector<QString> &,
                    const QVector<Event> &,
                    const QVector <QString> &);
private:

    class labelEvent{

    public:
        labelEvent(const Event &); //in verità se ne può occupare il controller
        labelEvent(const QString &,
                   const QString &,
                   const QString &,
                   const QString &);

        ~labelEvent();

        const QLabel* cgetBegin()const;
        const QLabel* cgetEnd()const;
        const QLabel* cgetDescription()const;
        const QLabel* cgetWhere()const;

    private:

        QLabel* begin;
        QLabel* end;
        QLabel* desc;
        QLabel* where;
    };

    QLabel* nick;
    QLabel* name;
    QLabel* surname;
    QLabel* birth;
    QLabel* phone;
    QLabel* eMail;

    QVector<QLabel*> hobby;
    QVector<QLabel*> interests;

    QVector<labelEvent*> experiences;

    QVector<QLabel*> friendships;
};

#endif // ADMINMWVIEWERVIEW_H
