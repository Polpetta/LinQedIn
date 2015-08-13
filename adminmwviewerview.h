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

#include <QDebug>

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
                    const QVector<QString> &,
                    const QVector <QString> &);
private:

    class listViewer : public QWidget{

    public:
        listViewer(QWidget * = nullptr);
        ~listViewer();

        void addLabel(QLabel*);
        void clear();

    private:

        QVector<QLabel*> obj; //da implmenetare distruttore
        QVBoxLayout* layout;

    };

    QLabel* nick;
    QLabel* name;
    QLabel* surname;
    QLabel* birth;
    QLabel* phone;
    QLabel* eMail;

    QScrollArea* scrollHobby;
    QScrollArea* scrollInterests;
    QScrollArea* scrollExperience;
    QScrollArea* scrollFriendships;

    listViewer* hobby;
    listViewer* interests;

    listViewer* experiences;

    listViewer* friendships;

};

#endif // ADMINMWVIEWERVIEW_H
