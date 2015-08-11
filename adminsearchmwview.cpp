#include "adminsearchmwview.h"

AdminSearchMWView::AdminSearchMWView(QWidget* parent)
    : QWidget (parent)
{}

AdminSearchMWView::~AdminSearchMWView()
{}


void AdminSearchMWView::closeEvent(QCloseEvent * event){

    emit requestClose( event );
}
