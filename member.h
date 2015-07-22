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
           const Profile & = Profile(),
           const Friendships & = Friendships());

    virtual ~Member();

    void addHobby(const QString &);
    void rmHobby (const QString &);

    void addInterest(const QString &);
    void rmInterest(const QString &);

    void addExperiences(const Event &);
    void rmExperiences(const Event &);

    void addFriend (const int &);
    void rmFriend (const int &);

    void setHobby(const Hobby &);
    void setInterest(const Interests &);
    void setFrinds(const Friendships &);

private:

    Profile info;
    Friendships friends;
};

#endif // MEMBER_H
