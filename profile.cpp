#include "profile.h"

Profile::Profile(const Personal& prs,
                 const Experiences & exp)
    : description(prs), career(exp)
{}


void Profile::setPersonal (const Personal &replace){

    description = replace;
}

void Profile::setExperiences(const Experiences &replace){

    career = replace;
}



Personal & Profile::getPersonal(){

    return description;
}

const Personal & Profile::cgetPersonal()const{

    return description;
}

Experiences & Profile::getExperiences(){

    return career;
}

const Experiences & Profile::cgetExperiences()const{

    return career;
}
