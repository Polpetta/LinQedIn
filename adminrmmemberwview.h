#ifndef ADMINRMMEMBERWVIEW_H
#define ADMINRMMEMBERWVIEW_H


#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class AdminRmMemberWView : public QWidget
{
    Q_OBJECT

public:
    AdminRmMemberWView(QWidget* = nullptr);

    ~AdminRmMemberWView();

signals:

    void requestClose ( QCloseEvent * );
    void remove (const QString &)const;

private slots:

    void confirmRemove()const;

protected:

    void closeEvent ( QCloseEvent * );

private:

    QLineEdit* target;
};

#endif // ADMINRMMEMBERWVIEW_H
