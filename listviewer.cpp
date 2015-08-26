#include "listviewer.h"

listViewer::listViewer(QWidget * ptr)
    : QWidget(ptr), layout (new QVBoxLayout)
{

    setLayout(layout);
}

listViewer::~listViewer(){

    QVector<QLabel*>::iterator it;
    for (it = obj.begin(); it != obj.end(); ++it){

        delete *it;
    }

    delete layout;
}

void listViewer::addLabel(QLabel* newLabel){

    obj.push_back(newLabel);

    layout->addWidget(obj.last());
}

void listViewer::addLabel(const QString & newLabel){

    QLabel* newInsert = new QLabel (newLabel);

    addLabel(newInsert);
}

void listViewer::clear(){

    QVector<QLabel*>::const_iterator it;

    for (it = obj.cbegin(); it != obj.cend(); ++it){

        layout->removeWidget(*it);
    }

    obj.clear();
}

void listViewer::changeLabel(const QString & old, const QString & replace){

    QVector<QLabel*>::iterator it;

    bool match = false;
    for (it = obj.begin(); it != obj.end() && match == false; ++it){

        if (old == (*it)->text()){

            (*it)->setText(replace);
        }
    }
}
