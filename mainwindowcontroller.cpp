#include "mainwindowcontroller.h"

MainWindowController::MainWindowController(MainWindowModel* nModel,
                                           MainWindowView* nView)
    : model (nModel), view (nView)
{

}


MainWindowController::~MainWindowController()
{
    delete model;
    delete view;

}
