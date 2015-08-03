#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "profile.h"
#include "friendships.h"

class Friendships;

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

    virtual void save (QXmlStreamWriter &) const;
    virtual void saveBack (QXmlStreamWriter &) const;
    virtual void load (QXmlStreamReader &);
    virtual void loadBack (QXmlStreamReader & );

private:

    Profile info;
    Friendships friends;
};

#endif // MEMBER_H
