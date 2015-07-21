#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "personal.h"
#include "experiences.h"
#include "friendships.h"

class Member : public User
{
public:
    Member(const QString &,
           const QString &,
           const Personal &);
    virtual ~Member();

    void addExperiences(const Event &);
    void rmExperiences(const Event &);

    void addHobby (const QString &);
    void rmHobby (const QString &);

    void addInterests (const QString &);
    void rmInterests (const QString &);

    void addFriend (const int &);
    void rmFriend (const int &);

private:

    Personal info;
    Experiences career;
    Friendships friends;
};

#endif // MEMBER_H
