#ifndef MSEARCHVIEWBASIC_H
#define MSEARCHVIEWBASIC_H

#include "msearchview.h"

class MSearchViewBasic : public MSearchView
{
    Q_OBJECT

public:
    MSearchViewBasic(QWidget* = nullptr);

    ~MSearchViewBasic();

signals:

    void searchConfirm(QString,
                       QString,
                       QString)const;

protected slots:

    virtual void commitSearch()const;


};

#endif // MSEARCHVIEWBASIC_H
