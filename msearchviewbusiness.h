#ifndef MSEARCHVIEWBUSINESS_H
#define MSEARCHVIEWBUSINESS_H

#include <QMessageBox>

#include "msearchviewbasic.h"

class MSearchViewBusiness : public MSearchViewBasic
{
    Q_OBJECT

public:
    MSearchViewBusiness(QWidget* = nullptr);

    ~MSearchViewBusiness();


signals:

    void emitNewHobby(const QString &)const;

public slots:

    void addFilterH()const;

private:

    void warnFilter()const;

    QLineEdit* hobbyEdit;
    QPushButton* addHobby;

};

#endif // MSEARCHVIEWBUSINESS_H
