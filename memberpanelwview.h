#ifndef MEMBERPANELWVIEW_H
#define MEMBERPANELWVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>

#include <QDebug>

class MemberPanelWView : public QWidget
{
    Q_OBJECT

signals:

    void execUpdateProfile();
    void execManageFriends();
    void execSearch();

    void requestClose( QCloseEvent* )const;

public:
    MemberPanelWView(QWidget* = nullptr);

    ~MemberPanelWView();

    void setAccountType(const QString &);

protected:

    void closeEvent( QCloseEvent * );

private:

    QLabel* typeAccount;
    QVBoxLayout* layoutTot;
};

#endif // MEMBERPANELWVIEW_H
