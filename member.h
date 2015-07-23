#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "profile.h"
#include "friendships.h"

//#include "credentials.h"
//qui ci va anche l'include di QString? compila anche senza
//qui ci va anche l'include di Event?

class Member : public User
{
public:
    Member(const Credentials & =Credentials(),
           const QString & = QString(),
           const Profile & = Profile(),
           const Friendships & = Friendships());

    virtual ~Member();


    Profile & getProfile();
    const Profile & cgetProfile()const;

    Friendships & getFriendships();
    const Friendships & cgetFriendships()const;

    void setProfile(const Profile &);
    void setFrinds(const Friendships &);

private:

    Profile info;
    Friendships friends;
};

#endif // MEMBER_H
