#ifndef MEMBERUPDATEWVIEW_H
#define MEMBERUPDATEWVIEW_H

#include <QWidget>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>

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

private:

    QLineEdit* name;
    QLineEdit* surname;
    QLineEdit* birth;
    QLineEdit* phone;
    QLineEdit* eMail;

    QPushButton* save;

};

#endif // MEMBERUPDATEWVIEW_H
