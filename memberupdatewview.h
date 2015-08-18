#ifndef MEMBERUPDATEWVIEW_H
#define MEMBERUPDATEWVIEW_H

#include <QWidget>

#include <QCloseEvent>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>

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

};

#endif // MEMBERUPDATEWVIEW_H
