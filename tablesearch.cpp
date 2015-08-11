#include "tablesearch.h"

TableSearch::TableSearch(QWidget* parent)
    : QWidget(parent)
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

    int row = newInfo->cgetRow();

    qDebug()<<"Riga: "<<row;

    results->addWidget(newInfo->getRow(), row, 0,Qt::AlignLeft);
    results->addWidget(newInfo->getInfo(), row, 1,Qt::AlignLeft);
    results->addWidget(newInfo->getDate(), row, 2, Qt::AlignLeft);
    results->addWidget(newInfo->getButton(), row, 3,Qt::AlignRight);
}



//info

TableSearch::info::info(const int & row,
                        const QString & nName,
                        const QString & nSurname,
                        const QString & nDate)
    //: QWidget(0)
{


    QString SRow(QString::number(row));
    rowNumber = new QLabel (SRow);

    information = new QLabel (nName+" "+
                              nSurname+" ");

    date = new QLabel ( tr("Data di nascita: " )+ nDate);

    details = new QPushButton (tr ("Dettagli ") );
}

TableSearch::info::~info(){

    delete rowNumber;
    delete information;
}

QLabel* TableSearch::info::getInfo(){

    return information;
}

QLabel* TableSearch::info::getDate(){

    return date;
}

QLabel* TableSearch::info::getRow(){

    return rowNumber;
}

int TableSearch::info::cgetRow()const{

    qDebug()<<"Text della rowNumber: "<<rowNumber->text();

    return rowNumber->text().toInt();
}

QPushButton* TableSearch::info::getButton(){

    return details;
}
