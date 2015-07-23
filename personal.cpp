#include "personal.h"

Personal::Personal(const Bio & bio,
                   const Hobby & hobby,
                   const Interests & interests)
    : info(bio),
      hbb(hobby),
      ntr(interests)

{}


void Personal::setBio(const Bio &replace){

    info = replace;
}


void Personal::setHobby (const Hobby &replace){

    hbb = replace;
}

void Personal::setInterests(const Interests &replace){

    ntr = replace;
}



Hobby & Personal::getHobby(){

    return hbb;
}

const Hobby & Personal::cgetHobby()const{

    return hbb;
}



Bio & Personal::getBio(){

    return info;
}

const Bio & Personal::cgetBio()const{

    return info;
}



Interests & Personal::getInterests(){

    return ntr;
}

const Interests & Personal::cgetInterests()const{

    return ntr;
}
