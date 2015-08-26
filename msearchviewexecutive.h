#ifndef MSEARCHVIEWEXECUTIVE_H
#define MSEARCHVIEWEXECUTIVE_H

#include "msearchviewbusiness.h"

class MSearchViewExecutive : public MSearchViewBusiness
{
    Q_OBJECT

public:
    MSearchViewExecutive(QWidget* = nullptr);

    ~MSearchViewExecutive();


signals:

    void emitNewInterests(const QString &)const;

public slots:

    void addFilterI()const;

private:

    void warnFilter() const;

    QLineEdit* interestsEdit;
    QPushButton* addInterests;

};

#endif // MSEARCHVIEWEXECUTIVE_H
