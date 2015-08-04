#include "memberbasic.h"

MemberBasic::MemberBasic(const Credentials & crd,
                         const QString & typ,
                         const Profile & prf,
                         const Friendships & frnd,
                         Database * ptr)
    : Member(crd,typ,prf,frnd, ptr)
{}

MemberBasic::~MemberBasic(){}

const DataMember& MemberBasic::search(const Profile & target) const{

    const QString & name = target.cgetPersonal().cgetBio().getName();
    const QString & surn = target.cgetPersonal().cgetBio().getSurname();

    Bio searchBase (name, surn);

    return getDb()->select(Profile(Personal(searchBase)));

}


