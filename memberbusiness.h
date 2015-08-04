#ifndef MEMBERBUSINESS_H
#define MEMBERBUSINESS_H

#include "memberbasic.h"

class MemberBusiness : public MemberBasic
{
public:
    MemberBusiness(const Credentials & = Credentials(),
                   const QString & = QString(),
                   const Profile & = Profile(),
                   const Friendships & = Friendships(),
                   Database* = nullptr);

    virtual ~MemberBusiness();

    virtual const DataMember& search(const Profile &) const;
};

#endif // MEMBERBUSINESS_H
