#include "memberloginwcontroller.h"

MemberLoginWController::MemberLoginWController(MemberLoginWModel* nModel,
                                               MemberLoginWView* nView)
    : model (nModel), view(nView)
{

    //qui ci andranno le connessioni
}


MemberLoginWController::~MemberLoginWController(){

    delete model;
    delete view;
}

void MemberLoginWController::showUI()const{

    view->show();
}
