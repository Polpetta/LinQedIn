#ifndef MSEARCHVIEW_H
#define MSEARCHVIEW_H

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

class MSearchView : public QWidget
{
    Q_OBJECT

protected:

    void closeEvent( QCloseEvent* );
    QVBoxLayout* getLayout()const;
    void enableBirthDay()const;

    QString getNameTex()const;
    QString getSurnameTex()const;
    QString getBirthDayTex()const;

public:

    MSearchView(QWidget* =nullptr);

    virtual ~MSearchView();

    TableSearch* getTable()const;

signals:

    void requestClose( QCloseEvent *)const;

protected slots:

    virtual void commitSearch()const =0;

private:

    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* birthDayEdit;
    QPushButton* search;

    TableSearch* result;
    QScrollArea* scrollResults;

    QVBoxLayout* layoutTot;


};

#endif // MSEARCHVIEW_H
