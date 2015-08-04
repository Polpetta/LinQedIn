#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "profile.h"
#include "friendships.h"
#include "credentials.h"

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

    Credentials & getCredential();
    const Credentials & cgetCredential()const;

    void setCredential(const Credentials &);
    void setProfile(const Profile &);
    void setFrinds(const Friendships &);

    virtual void save (QXmlStreamWriter &) const;
    virtual void saveBack (QXmlStreamWriter &) const;
    virtual void load (QXmlStreamReader &);
    virtual void loadBack (QXmlStreamReader & );

private:

    Credentials logCrd;
    Profile info;
    Friendships friends;
};

#endif // MEMBER_H
