#ifndef ADMINWINDOWVIEW_H
#define ADMINWINDOWVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>

class AdminWindowView : public QWidget
{
    Q_OBJECT

signals:

    void addMember();
    void searchMember();
    void rmMember();
    void changeMember();
    void saveDb();


public:
    AdminWindowView( QWidget* = nullptr );
};

#endif // ADMINWINDOWVIEW_H
