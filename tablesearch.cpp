#include "tablesearch.h"

TableSearch::TableSearch(QWidget* parent)
    : QWidget(parent), separatorNumber (0)
{

    results = new QGridLayout;

    setLayout(results);
}

TableSearch::~TableSearch(){

    delete results;
}

void TableSearch::addRow(const QString & nName,
                         const QString & nSurname,
                         const QString & nDate) {
    TableSearch::info* newInfo = new TableSearch::info (items.count()+1,
                                                        nName,
                                                        nSurname,
                                                        nDate);

    items.push_back(newInfo);

    int lRow = newInfo->cgetRow();

    QLabel* row = new QLabel (QString::number(lRow-separatorNumber));

    results->addWidget(row, lRow, 0,Qt::AlignLeft);
    results->addWidget(newInfo->getInfo(), lRow, 1,Qt::AlignLeft);
    results->addWidget(newInfo->getDate(), lRow, 2, Qt::AlignLeft);
    results->addWidget(newInfo->getButton(), lRow, 3,Qt::AlignRight);
}

void TableSearch::addSeparator(){

    TableSearch::info* fake = new TableSearch::info (items.count()+1);
    QLabel* separator = new QLabel ("");


    ++separatorNumber;
    items.push_back(fake);

    int row = fake->cgetRow();

    results->addWidget(separator, row, 0, Qt::AlignCenter);

}

void TableSearch::disableOldResult(){

    QList<TableSearch::info*>::const_iterator it;

    for (it = items.cbegin(); it != items.cend(); ++it){

        QPushButton* toDisable = (*it)->getButton();
        if (toDisable != nullptr)
            toDisable->setEnabled( false );
    }

    //non pulisco items perchè voglio tenere lo storico dei risultati
}



//info

TableSearch::info::info(const int & row)
    : rowNumber(row),
      information (nullptr),
      date (nullptr),
      details(nullptr)
{}

TableSearch::info::info(const int & row,
                        const QString & nName,
                        const QString & nSurname,
                        const QString & nDate)
    :rowNumber (row)
{

    information = new QLabel (nName+" "+
                              nSurname+" ");

    date = new QLabel ( tr("Data di nascita: " )+ nDate);

    details = new QPushButton (tr ("Dettagli ") );
}

TableSearch::info::~info(){

    delete information;
    delete date;
    delete details;
}

QLabel* TableSearch::info::getInfo(){

    return information;
}

QLabel* TableSearch::info::getDate(){

    return date;
}

int TableSearch::info::cgetRow()const{

    return rowNumber;
}

QPushButton* TableSearch::info::getButton(){

    return details;
}

QPushButton* TableSearch::getButtonLastItem()const{

    return items.last()->getButton();
}
