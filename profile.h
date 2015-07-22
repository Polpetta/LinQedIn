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

    void addHobby(const QString &);
    void rmHobby (const QString &);

    void addInterest(const QString &);
    void rmInterest(const QString &);

    void addExperiences (const Event &);
    void rmExperiences (const Event &);

    void setPersonal(const Personal &);
    void setExperiences(const Experiences &);
    void setHobby(const Hobby &);
    void setInterest(const Interests &);


private:

    Personal description;
    Experiences career;
};

#endif // PROFILE_H
