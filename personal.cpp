#include "personal.h"

Personal::Personal(QDate bd,
                   QString nm,
                   QString srn,
                   QString phn,
                   QString eMl,
                   bool src)
    : birthDay(bd),
      name(nm),
      surname(srn),
      phone(phn),
      eMail(eMl),
      searchingJob(src)

{}

void Personal::addHobby(const QString &newHobby){

    hbb.add(newHobby);
}

void Personal::rmHobby(const QString & target){

    hbb.rm(target);
}



void Personal::addInterest(const QString &newInterest){

    ntr.add(newInterest);
}

void Personal::rmInterest(const QString & target){

    ntr.rm(target);
}

bool Personal::isSearching()const{

    return searchingJob;
}

int Personal::getAge()const{

    int yb = birthDay.year();

    int currenty = QDate::currentDate().year();

    return currenty - yb;
}

QDate Personal::getBirthday()const{

    return birthDay;
}

void Personal::setName(const QString &newName){

    name = newName;
}

void Personal::setSurname(const QString &newSurname){

    surname = newSurname;
}

void Personal::setPhone(const QString &newNumber){

    phone = newNumber;
}

void Personal::setEmail(const QString &newMail){

    eMail = newMail;
}

void Personal::setBirthDay(const QDate &newBD){

    birthDay = newBD;
}
