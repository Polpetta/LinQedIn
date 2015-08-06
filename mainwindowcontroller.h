#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>

#include "mainwindowmodel.h"
#include "mainwindowview.h"

class MainWindowController : QObject
{
    Q_OBJECT

private:

    MainWindowModel* model;
    MainWindowView* view;

public:
    MainWindowController(MainWindowModel* = new MainWindowModel,
                         MainWindowView* = new MainWindowView);

    ~MainWindowController();


};

#endif // MAINWINDOWCONTROLLER_H
