#ifndef ADMINSEARCHMWVIEW_H
#define ADMINSEARCHMWVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>

class AdminSearchMWView : public QWidget
{
    Q_OBJECT

public:
    AdminSearchMWView(QWidget* = nullptr);

    ~AdminSearchMWView();

signals:

    void requestClose( QCloseEvent * );

protected:

    void closeEvent( QCloseEvent * );

private:

    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* birthDayEdit;

    QLineEdit* hobbyEdit;
    QLineEdit* interestsEdit;


};

#endif // ADMINSEARCHMWVIEW_H
