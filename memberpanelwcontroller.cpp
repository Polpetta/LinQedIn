#include "memberpanelwcontroller.h"

MemberPanelWController::MemberPanelWController(MemberPanelWModel* nModel,
                                               MemberPanelWView* nView)
    : model(nModel), view(nView)
{

    //ci andranno le varie connect
}

MemberPanelWController::~MemberPanelWController(){


}

void MemberPanelWController::showUI()const{

    view->show();
}
