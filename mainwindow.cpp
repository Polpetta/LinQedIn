#include "mainwindow.h"

MainWindow::MainWindow()
{

    w = new MainWindowController;

    w->showUI();
}

MainWindow::~MainWindow()
{

    delete w;
}
