#ifndef MVIEWERVIEWEXECUTIVE_H
#define MVIEWERVIEWEXECUTIVE_H

#include "mviewerviewbusiness.h"

class MViewerViewExecutive : public MViewerViewBusiness
{
public:
    MViewerViewExecutive(QWidget* = nullptr);

    ~MViewerViewExecutive();

protected:

    virtual void setToShow()const;
};

#endif // MVIEWERVIEWEXECUTIVE_H
