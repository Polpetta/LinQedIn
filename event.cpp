#include "event.h"

Event::Event(QDate nbg, QDate nfn, QString ndsc, QString nwhr)
    : begin(nbg), finish(nfn), desc(ndsc), where(nwhr)
{}

int Event::timeEvent() const {
    if (finish.isNull())
        return -1;

    return begin.daysTo(finish);
}

QString Event::getEvent() const {

    QString result;

    QString bg = begin.toString("dd.MM.yyyy");
    QString fn = finish.toString("dd.MM.yyyy");

    result = bg + " - " + fn + "in " + where + ": " + desc;
    return result;
}

void Event::setDesc(QString newDesc) {

    desc = newDesc;
}

void Event::setWhere(QString newWhere) {

    where = newWhere;
}

void Event::setBegin(QDate newBg) {

    begin = newBg;
}

void Event::setFinish(QDate newFn) {

    finish = newFn;
}
