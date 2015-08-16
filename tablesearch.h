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

    void addSeparator();


    QPushButton* getButtonLastItem()const;

    void disableOldResult();

private:

    class info //: public QWidget
    {

    public:
        info (const int &,
              const QString &,
              const QString &,
              const QString &);

        info(const int &);

        ~info();

        QLabel* getInfo();
        QLabel* getDate();
        QPushButton* getButton();
        int cgetRow()const;

    private:

        int rowNumber;
        QLabel* information;
        QLabel* date;
        QPushButton* details;

    };


    int separatorNumber;
    QGridLayout* results;
    QList<TableSearch::info*> items;
};

#endif // TABLESEARCH_H
