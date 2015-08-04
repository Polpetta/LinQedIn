#ifndef MEMBEREXECUTIVE_H
#define MEMBEREXECUTIVE_H

#include "memberbusiness.h"

class MemberExecutive : public MemberBusiness
{
public:
    MemberExecutive(const Credentials & = Credentials(),
                    const QString & = QString(),
                    const Profile & = Profile(),
                    const Friendships & = Friendships(),
                    Database * = nullptr);

    virtual ~MemberExecutive();

    virtual const DataMember& search(const Profile &) const;
};

#endif // MEMBEREXECUTIVE_H
