#ifndef ADMINMWVIEWERVIEW_H
#define ADMINMWVIEWERVIEW_H


#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QGroupBox>
#include <QVBoxLayout>

#include <QDebug>

#include "listviewer.h"

class AdminMWViewerView : public QWidget
{

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
