#ifndef MEMBERLOGINWVIEW_H
#define MEMBERLOGINWVIEW_H


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MemberLoginWView : public QWidget
{
    Q_OBJECT

public:
    MemberLoginWView(QWidget* = nullptr);

    ~MemberLoginWView();

private:

    QLineEdit* nickLogin;
};

#endif // MEMBERLOGINWVIEW_H
