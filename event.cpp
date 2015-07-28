#include "event.h"

Event::Event(const QDate &nbg,
             const QDate &nfn,
             const QString &ndsc,
             const QString &nwhr)
    : begin(nbg),
      finish(nfn),
      desc(ndsc),
      where(nwhr)
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

    result = bg + " - " + fn + " :: " + where + ": " + desc;

    return result;
}

void Event::setDesc(const QString & newDesc) {

    desc = newDesc;
}

void Event::setWhere(const QString & newWhere) {

    where = newWhere;
}

void Event::setBegin(const QDate &newBg) {

    begin = newBg;
}

void Event::setFinish(const QDate &newFn) {

    finish = newFn;
}

//OPERATORI

bool Event::operator ==(const Event & ev)const{

    return begin == ev.begin &&
            finish == ev.finish &&
            desc == ev.desc &&
            where == ev.where;
}

bool Event::operator !=(const Event & ev)const{

    return begin != ev.begin ||
            finish != ev.finish ||
            desc != ev.desc ||
            where != ev.where;
}

//------------

const QDate & Event::cgetBegin()const{

    return begin;
}

const QDate & Event::cgetFinish()const{

    return finish;
}

const QString & Event::cgetDesc()const{

    return desc;
}

const QString & Event::cgetWhere() const{

    return where;
}
