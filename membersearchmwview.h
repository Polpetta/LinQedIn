#ifndef MEMBERSEARCHMWVIEW_H
#define MEMBERSEARCHMWVIEW_H

#include <QWidget>
#include <QCloseEvent>

#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QMessageBox>

#include "tablesearch.h"
#include "event.h"

class MemberSearchMWView : public QWidget
{
    Q_OBJECT

signals:

    void requestClose( QCloseEvent *)const;

private slots:

    void addFilterH()const;
    void addFilterI()const;

public:
    MemberSearchMWView(QWidget* = nullptr);

    ~MemberSearchMWView();

    TableSearch* getTable()const;

    void blockBio()const;
    void blockHobby()const;
    void blockInterests()const;

    void setNote(const QString &);

protected:

    void closeEvent( QCloseEvent* );

private:

    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* birthDayEdit;
    QPushButton* search;

    QLineEdit* hobbyEdit;
    QPushButton* addHobby;
    QLineEdit* interestsEdit;
    QPushButton* addInterests;


    TableSearch* result;
    QScrollArea* scrollResults;

    QVBoxLayout* layoutTot;

};

#endif // MEMBERSEARCHMWVIEW_H
