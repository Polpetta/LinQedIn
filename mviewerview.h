#ifndef MVIEWERVIEW_H
#define MVIEWERVIEW_H

#include <QWidget>

#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QGroupBox>
#include <QVBoxLayout>

#include "listviewer.h"

class MViewerView : public QWidget
{
    Q_OBJECT

public:
    MViewerView(QWidget* = nullptr);

    virtual ~MViewerView();

    void setProfile(const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QString &,
                    const QVector<QString> &,
                    const QVector<QString> &,
                    const QVector<QString> &,
                    const QVector<QString> &);

    void resetLayout();

public slots:

    void show();

protected:

    QVBoxLayout* getLayout()const;

    QGroupBox* getCredential()const;
    QGroupBox* getBio()const;
    QGroupBox* getFriendships()const;
    QGroupBox* getHobby()const;
    QGroupBox* getInterests()const;
    QGroupBox* getExperiences()const;

    virtual void setToShow()const =0;

private:

    void initialize();
    void build();
    void clearList();

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

    QGroupBox* credentialBox;
    QGroupBox* bioBox;
    QGroupBox* friendshipsBox;
    QGroupBox* hobbyBox;
    QGroupBox* interestsBox;
    QGroupBox* experiencesBox;

    QGridLayout* crdLayout;

    QGridLayout* bioLayout;

    QScrollArea* scrollFriendships;
    QGridLayout* friendshipsLayout;

    QScrollArea* scrollHobby;
    QGridLayout* hobbyLayout;

    QScrollArea* scrollInterests;
    QGridLayout* interestsLayout;

    QScrollArea* scrollExperiences;
    QGridLayout* experiencesLayout;
};

#endif // MVIEWERVIEW_H
