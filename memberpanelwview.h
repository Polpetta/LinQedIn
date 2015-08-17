#ifndef MEMBERPANELWVIEW_H
#define MEMBERPANELWVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>

class MemberPanelWView : public QWidget
{
    Q_OBJECT

signals:

    void execUpdateProfile();
    void execManageFriends();
    void execSearch();

public:
    MemberPanelWView(QWidget* = nullptr);

    ~MemberPanelWView();
};

#endif // MEMBERPANELWVIEW_H
