#ifndef ADMINSEARCHMWVIEW_H
#define ADMINSEARCHMWVIEW_H

#include <QWidget>

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
};

#endif // ADMINSEARCHMWVIEW_H
