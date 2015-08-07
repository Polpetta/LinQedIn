#include "adminaddmemberwc.h"

AdminAddMemberWC::AdminAddMemberWC(AdminAddMemberWM* nModel,
                                   AdminAddMemberWV* nView)
    : model (nModel), view (nView)
{

    //verranno create le varie connessioni

}

AdminAddMemberWC::~AdminAddMemberWC()
{

    delete model;
    delete view;
}

void AdminAddMemberWC::showUI(){

    view->show();
    view->restart();
}
