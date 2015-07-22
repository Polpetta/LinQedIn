#include "personal.h"

Personal::Personal(const Bio & bio,
                   const Hobby & hobby,
                   const Interests & interests)
    : info(bio),
      hbb(hobby),
      ntr(interests)

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



void Personal::setBio(const Bio &replace){

    info = replace;
}


void Personal::setHobby (const Hobby &replace){

    hbb = replace;
}

void Personal::setInterests(const Interests &replace){

    ntr = replace;
}
