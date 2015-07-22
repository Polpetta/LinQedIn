#include "profile.h"

Profile::Profile(const Personal& prs,
                 const Experiences & exp)
    : description(prs), career(exp)
{}


void Profile::addHobby(const QString & newHobby){

    description.addHobby(newHobby);
}

void Profile::rmHobby (const QString & target){

    description.rmHobby(target);
}



void Profile::addInterest(const QString & newInterest){

    description.addInterest(newInterest);
}

void Profile::rmInterest(const QString & target){

    description.rmInterest(target);
}


void Profile::addExperiences(const Event & newEvent){

    career.add(newEvent);
}

void Profile::rmExperiences(const Event & target){

    career.rm(target);
}



void Profile::setPersonal (const Personal &replace){

    description = replace;
}

void Profile::setExperiences(const Experiences &replace){

    career = replace;
}

void Profile::setHobby(const Hobby &replace){

    description.setHobby(replace);
}

void Profile::setInterest(const Interests &replace){

    description.setInterests(replace);
}
