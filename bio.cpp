#include "bio.h"

Bio::Bio(const QDate & bd,
         const QString & nm,
         const QString & srn,
         const QString & phn,
         const QString & eMl)
    : birthDay(bd),
      name(nm),
      surname(srn),
      phone(phn),
      eMail(eMl)
{}

QString Bio::getName()const{

    return name;
}

QString Bio::getSurname()const{

    return surname;
}

QString Bio::getPhone()const{

    return phone;
}

QString Bio::getMail()const{

    return eMail;
}

int Bio::getAge()const{

    int yb = birthDay.year();

    int currenty = QDate::currentDate().year();

    return currenty - yb;
}

QDate Bio::getBirthday()const{

    return birthDay;
}



void Bio::setBirthday(const QDate &newBD){

    birthDay = newBD;
}

void Bio::setName(const QString &newName){

    name = newName;
}

void Bio::setSurname(const QString &newSurname){

    surname = newSurname;
}

void Bio::setPhone(const QString &newPhone){

    phone = newPhone;
}

void Bio::setMail(const QString &newMail){

    eMail = newMail;
}
