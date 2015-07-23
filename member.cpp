#include "member.h"

Member::Member(const Credentials & crd,
               const Profile & prf,
               const Friendships & frnd)

    : User(crd), info(prf), friends(frnd)
{}

Member::~Member()
{}

Profile & Member::getProfile(){

    return info;
}

const Profile & Member::cgetProfile()const{

    return info;
}

Friendships & Member::getFriendships(){

    return friends;
}

const Friendships & Member::cgetFriendships()const{

    return friends;
}


void Member::setProfile(const Profile & replace){

    info = replace;
}

void Member::setFrinds(const Friendships & replace){

    friends = replace;
}
