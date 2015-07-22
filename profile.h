#ifndef PROFILE_H
#define PROFILE_H

#include "personal.h"
#include "experiences.h"

class Profile
{
public:
    Profile(const Personal & = Personal(),
            const Experiences & = Experiences()
            );

    void setPersonal(const Personal &);
    void setExperiences(const Experiences &);

private:

    Personal description;
    Experiences career;
};

#endif // PROFILE_H
