#ifndef ADMINCHANGETYPEWVIEW_H
#define ADMINCHANGETYPEWVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

class AdminChangeTypeWView : public QWidget
{
    Q_OBJECT

signals:

    void changeType (const QString &, const QString &)const;
    void requestClose (QCloseEvent *);

private slots:

    void execChangeType()const;

public:
    AdminChangeTypeWView(QWidget* = nullptr);

protected:

    void closeEvent ( QCloseEvent * );

private:

    QLineEdit* nick;
    QLineEdit* newType;
};

#endif // ADMINCHANGETYPEWVIEW_H
