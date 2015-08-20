#ifndef MEMBERMWVIEWERVIEW_H
#define MEMBERMWVIEWERVIEW_H

#include <QWidget>

#include <QDebug>

#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QGroupBox>
#include <QVBoxLayout>

#include "listviewer.h"


class MemberMWViewerView : public QWidget
{
public:
    MemberMWViewerView(QWidget* = nullptr);

    ~MemberMWViewerView();

    void addHobby(const QVector<QString> &);
    void addInterests(const QVector<QString> &);
    void addExperiences(const QVector<QString> &);

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString> &);

private:

    QLabel* nick;
    QLabel* name;
    QLabel* surname;
    QLabel* birth;
    QLabel* phone;
    QLabel* eMail;

    QVBoxLayout* layoutTot;

    listViewer* hobby;
    listViewer* interests;

    listViewer* experiences;

    listViewer* friendships;

};

#endif // MEMBERMWVIEWERVIEW_H
