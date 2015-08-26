#ifndef MVIEWERVIEWBASIC_H
#define MVIEWERVIEWBASIC_H

#include "mviewerview.h"

class MViewerViewBasic : public MViewerView
{
public:
    MViewerViewBasic(QWidget * = nullptr);

    ~MViewerViewBasic();

protected:

    virtual void setToShow()const;

};

#endif // MVIEWERVIEWBASIC_H
