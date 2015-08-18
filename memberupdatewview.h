#ifndef MEMBERUPDATEWVIEW_H
#define MEMBERUPDATEWVIEW_H

#include <QWidget>

#include <QCloseEvent>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QScrollArea>

#include "listviewer.h"

class MemberUpdateWView : public QWidget
{
    Q_OBJECT

signals:

    void saveBio(const QString &,
                 const QString &,
                 const QString &,
                 const QString &,
                 const QString &)const;
    void execModHobby()const;
    void execModInterests()const;
    void execModExperiences()const;

    void requestClose ( QCloseEvent* );

private slots:

    void groupBio()const;

public:
    MemberUpdateWView(QWidget * = nullptr);

    ~MemberUpdateWView();

    void setBio(const QString &,
                const QString &,
                const QString &,
                const QString &,
                const QString &);

protected:

    void closeEvent(QCloseEvent *);

private:

    QLineEdit* name;
    QLineEdit* surname;
    QLineEdit* birth;
    QLineEdit* phone;
    QLineEdit* eMail;

    QPushButton* save;


    QLineEdit* modifyHobby;
    listViewer* hobby;

    QPushButton* addHobby;
    QPushButton* rmHobby;


    QLineEdit* modifyInterests;
    listViewer* interests;

    QPushButton* addInterests;
    QPushButton* rmInterests;


    QLineEdit* modifyExpBegin;
    QLineEdit* modifyExpFinish;
    QLineEdit* modifyExpDesc;
    QLineEdit* modifyExpWhere;
    listViewer* experiences;

    QPushButton* addExperiences;
    QPushButton* rmExperiences;

};

#endif // MEMBERUPDATEWVIEW_H
