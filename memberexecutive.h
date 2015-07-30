#ifndef MEMBEREXECUTIVE_H
#define MEMBEREXECUTIVE_H

#include "memberbusiness.h"

class MemberExecutive : public MemberBusiness
{
public:
    MemberExecutive(const Credentials & = Credentials(),
                    const QString & = QString(),
                    const Profile & = Profile(),
                    const Friendships & = Friendships());

    virtual ~MemberExecutive();

    virtual UserData& search(const QString &) const;
};

#endif // MEMBEREXECUTIVE_H
