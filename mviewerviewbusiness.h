#ifndef MVIEWERVIEWBUSINESS_H
#define MVIEWERVIEWBUSINESS_H

#include "mviewerviewbasic.h"

class MViewerViewBusiness : public MViewerViewBasic
{
public:
    MViewerViewBusiness(QWidget* = nullptr);

    ~MViewerViewBusiness();

protected:

    virtual void setToShow()const;
};

#endif // MVIEWERVIEWBUSINESS_H
