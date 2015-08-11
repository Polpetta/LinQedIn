#ifndef TABLESEARCH_H
#define TABLESEARCH_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QList>
#include <QLabel>

#include <QDebug>


class TableSearch : public QWidget
{
    Q_OBJECT

public:
    TableSearch(QWidget* = nullptr);

    ~TableSearch();

    void addRow(const QString &,
                const QString &,
                const QString &);


private:

    class info //: public QWidget
    {

    public:
        info (const int &,
              const QString &,
              const QString &,
              const QString &);

        ~info();

        QLabel* getInfo();
        QLabel* getDate();
        QLabel* getRow();
        QPushButton* getButton();
        int cgetRow()const;

    private:

        QLabel* rowNumber;
        QLabel* information;
        QLabel* date;
        QPushButton* details;

    };

    QGridLayout* results;
    QList<TableSearch::info*> items;
};

#endif // TABLESEARCH_H
