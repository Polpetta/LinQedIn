#ifndef MEMBERBUSINESS_H
#define MEMBERBUSINESS_H

#include "memberbasic.h"

class MemberBusiness : public MemberBasic
{
public:
    MemberBusiness(const Credentials & = Credentials(),
                   const QString & = QString(),
                   const Profile & = Profile(),
                   const Friendships & = Friendships());

    virtual ~MemberBusiness();

    virtual DataMember& search(const QString &) const;
};

#endif // MEMBERBUSINESS_H
