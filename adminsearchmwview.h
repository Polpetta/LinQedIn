#ifndef ADMINSEARCHMWVIEW_H
#define ADMINSEARCHMWVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>

#include "tablesearch.h"

class AdminSearchMWView : public QWidget
{
    Q_OBJECT    

public:

    AdminSearchMWView(QWidget* = nullptr);

    ~AdminSearchMWView();

signals:

    void requestClose( QCloseEvent * );

    void newHobbyFilter (const QString &);
    void newInterestsFilter (const QString &);

    void searchConfirm (const QString &,
                        const QString &,
                        const QString &);

public slots:

    void newFilterH();
    void newFilterI();

    void commitSearch();

protected:

    void closeEvent( QCloseEvent * );

private:

    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* birthDayEdit;

    QLineEdit* hobbyEdit;
    QLineEdit* interestsEdit;

    TableSearch* result;
    QScrollArea* scrollResults;

};

#endif // ADMINSEARCHMWVIEW_H
