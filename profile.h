#ifndef PROFILE_H
#define PROFILE_H

#include "personal.h"
#include "experiences.h"
#include "event.h"

class Profile
{
public:
    Profile(const Personal & = Personal(),
            const Experiences & = Experiences()
            );


    void setPersonal(const Personal &);
    void setExperiences(const Experiences &);

    Personal & getPersonal();
    const Personal & cgetPersonal()const;

    Experiences & getExperiences();
    const Experiences & cgetExperiences()const;


private:

    Personal description;
    Experiences career;
};

#endif // PROFILE_H
