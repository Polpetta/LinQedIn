#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H


#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindowView : public QWidget
{
    Q_OBJECT

signals:

    void adminViewCall();

public:
    MainWindowView( QWidget* = nullptr );

};

#endif // MAINWINDOWVIEW_H
