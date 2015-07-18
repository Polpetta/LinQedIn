#ifndef EVENT_H
#define EVENT_H

#include <QDate>
#include <QString>

class Event
{
public:
    Event(QDate, QDate, QString, QString);

    int timeEvent() const;
    QString getEvent() const;

    void setDesc(QString);
    void setWhere(QString);

    void setBegin(QDate);
    void setFinish(QDate);

private:
    QDate begin;
    QDate finish;
    QString desc;
    QString where;
};

#endif // EVENT_H
