#include "member.h"

Member::Member(const Credentials & crd,
               const Profile & prf,
               const Friendships & frnd)

    : User(crd), info(prf), friends(frnd)
{}

Member::~Member()
{}

void Member::addHobby(const QString &newHobby){

    info.addHobby(newHobby);
}

void Member::rmHobby(const QString &target){

    info.rmHobby(target);
}



void Member::addInterest(const QString &newInterest){

    info.addInterest(newInterest);
}

void Member::rmInterest(const QString &target){

    info.rmInterest(target);
}



void Member::addExperiences(const Event & newEvent){

    info.addExperiences(newEvent);
}

void Member::rmExperiences(const Event & target){

    info.rmExperiences(target);
}



void Member::addFriend(const int & newFriendId){

    friends.add(newFriendId);
}

void Member::rmFriend(const int & target){

    friends.rm(target);
}



void Member::setHobby(const Hobby & replace){

    info.setHobby(replace);
}

void Member::setInterest(const Interests &replace){

    info.setInterest(replace);
}

void Member::setFrinds(const Friendships & replace){

    friends = replace;
}
