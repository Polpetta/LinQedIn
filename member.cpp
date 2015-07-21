#include "member.h"

Member::Member(const QString & usr,
               const QString & pswd,
               const Personal & prs)
    : User(usr,pswd), info(prs)
{}

Member::~Member()
{}

void Member::addExperiences(const Event & newEvent){

    career.Experiences::add(newEvent);
}

void Member::rmExperiences(const Event & target){

    career.Experiences::rm(target);
}



void Member::addHobby(const QString & newHobby){

    info.Personal::addHobby(newHobby);
}

void Member::rmHobby(const QString & target){

    info.Personal::rmHobby(target);
}



void Member::addInterests(const QString & newInterests){

    info.Personal::addInterest(newInterests);
}

void Member::rmInterests(const QString & target){

    info.Personal::rmInterest(target);
}


void Member::addFriend(const int & newFriendId){

    friends.add(newFriendId);
}

void Member::rmFriend(const int & target){

    friends.rm(target);
}
