#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "personal.h"
#include "experiences.h"
//MANCA LA CLASSE AMICIZIE - da fare

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

private:

    Personal info;
    Experiences career;
    //manca la classe amicizie
};

#endif // MEMBER_H
