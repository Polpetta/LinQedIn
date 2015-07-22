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
