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

int Bio::getAge()const{

    int yb = birthDay.year();

    int currenty = QDate::currentDate().year();

    return currenty - yb;
}

QDate Bio::getBirthday()const{

    return birthDay;
}
