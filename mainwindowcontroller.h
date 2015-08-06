#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QObject>

#include "mainwindowmodel.h"
#include "mainwindowview.h"

class MainWindowController : public QObject
{
    Q_OBJECT

private:

    MainWindowModel* model;
    MainWindowView* view;

public slots:

    void showAdmin();

public:
    MainWindowController(MainWindowModel* = new MainWindowModel,
                         MainWindowView* = new MainWindowView);

    void showUI();

    ~MainWindowController();


};

#endif // MAINWINDOWCONTROLLER_H
