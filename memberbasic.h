#ifndef MEMBERBASIC_H
#define MEMBERBASIC_H

#include <QString>

#include "member.h"
#include "credentials.h"
#include "profile.h"
#include "friendships.h"


class MemberBasic : public Member
{
public:
    MemberBasic(const Credentials & = Credentials(),
                const QString & = QString(),
                const Profile & = Profile(),
                const Friendships & = Friendships(),
                Database* = nullptr);

    virtual ~MemberBasic();

    virtual const DataMember& search(const Profile &) const;
};

#endif // MEMBERBASIC_H
