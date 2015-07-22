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

    void addHobby(const QString &);
    void rmHobby(const QString &);

    void addInterest(const QString &);
    void rmInterest(const QString &);

    void setBio(const Bio &);
    void setHobby(const Hobby &);
    void setInterests(const Interests &);

private:

    Bio info;
    Hobby hbb;
    Interests ntr;
};

#endif // PERSONAL_H
