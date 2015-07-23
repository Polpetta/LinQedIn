#ifndef PERSONAL_H
#define PERSONAL_H

#include "bio.h"
#include "hobby.h"
#include "interests.h"


class Personal
{
public:
    Personal(const Bio & = Bio(),
             const Hobby & = Hobby(),
             const Interests & = Interests()
            );

    void setBio(const Bio &);
    void setHobby(const Hobby &);
    void setInterests(const Interests &);

    Hobby & getHobby();
    const Hobby & cgetHobby()const;

    Bio & getBio();
    const Bio & cgetBio()const;

    Interests & getInterests();
    const Interests & cgetInterests()const;

private:

    Bio info;
    Hobby hbb;
    Interests ntr;
};

#endif // PERSONAL_H
