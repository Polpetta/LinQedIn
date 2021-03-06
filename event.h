#ifndef EVENT_H
#define EVENT_H

#include <QDate>
#include <QString>

class Event
{
public:

    Event(const QDate & = QDate(),
          const QDate & = QDate(),
          const QString & = QString(),
          const QString & = QString()
          );

    Event(const QString &,
          const QString &,
          const QString &,
          const QString &,
          const QString &);

    int timeEvent() const;
    QString toString() const;

    void setDesc(const QString &);
    void setWhere(const QString &);

    void setBegin(const QDate &);
    void setFinish(const QDate &);

    bool operator == (const Event &) const;
    bool operator != (const Event &) const;

    const QDate & cgetBegin()const;
    const QDate & cgetFinish()const;
    const QString & cgetDesc()const;
    const QString & cgetWhere()const;

    bool isValid()const;

private:
    QDate begin;
    QDate finish;
    QString desc;
    QString where;
};

#endif // EVENT_H
