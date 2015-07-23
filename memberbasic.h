#ifndef MEMBERBASIC_H
#define MEMBERBASIC_H

#include "member.h"
#include "credentials.h"
#include "profile.h"
#include "friendships.h"
#include <QString>
//MANCA L'INCLUSIONE DELLA CLASSE SEARCH

class MemberBasic : public Member
{
public:
    MemberBasic(const Credentials & = Credentials(),
                const QString & = QString(),
                const Profile & = Profile(),
                const Friendships & = Friendships());

    virtual ~MemberBasic();

    virtual vector<SmartUtente>& search(const QString &) const;
};

#endif // MEMBERBASIC_H
