#include "adminwindowcontroller.h"

AdminWindowController::AdminWindowController(AdminWindowModel* nModel,
                                             AdminWindowView* nView,
                                             SmartAdmin newAdm)
    :  model(nModel), view(nView), admin (newAdm)
{
    //creare le connect adatte
}

AdminWindowController::~AdminWindowController()
{

    delete model;
    delete view;
    //ci sarà la delete dell'admin, implicita
}


void AdminWindowController::showUI(){

    view->show();
}
