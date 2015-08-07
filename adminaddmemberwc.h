#ifndef ADMINADDMEMBERWC_H
#define ADMINADDMEMBERWC_H

#include <QObject>

#include "adminaddmemberwm.h"
#include "adminaddmemberwv.h"

class AdminAddMemberWC : public QObject
{
    Q_OBJECT

public:
    AdminAddMemberWC(AdminAddMemberWM* = new AdminAddMemberWM,
                     AdminAddMemberWV* = new AdminAddMemberWV);

    ~AdminAddMemberWC();

    void showUI();

private:

    AdminAddMemberWM* model;
    AdminAddMemberWV* view;
};

#endif // ADMINADDMEMBERWC_H
