#ifndef MEMBER_H
#define MEMBER_H

#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "user.h"
#include "profile.h"
#include "friendships.h"
#include "credentials.h"

#include "database.h"
//includo ora il db così evito problemi di compilazione

//#include "datamember.h"
class DataMember;

class Member : public User
{
public:
    Member(const Credentials & =Credentials(),
           const QString & = QString(),
           const Profile & = Profile(),
           const Friendships & = Friendships(),
           Database* = nullptr);

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

    virtual const DataMember& search(const Profile&)const =0;
    /*
     * Decisione della serach:
     * Basic -> Nome e Cognome
     * Business -> Basic + Hobby e Interests
     * Executive -> Tutto
     *
     * L'idea è che ogni classe crei un "filtro" il Profile passato
     * e lo renda conforme alla ricerca che si vuole:
     * ad Esempio: search su basic viene passato un Profile completo.
     * Di questo, se ne prendereanno solamente Nome e Cognome e si chiamerà
     * la funzione search del database.
     */

private:

    Credentials logCrd;
    Profile info;
    Friendships friends;
};

#endif // MEMBER_H
