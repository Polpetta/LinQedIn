#include "memberbusiness.h"

MemberBusiness::MemberBusiness(const Credentials & crd,
                               const QString & typ,
                               const Profile & prf,
                               const Friendships & frnd)
    : MemberBasic (crd,typ,prf,frnd)
{}

MemberBusiness::~MemberBusiness() {}

DataMember& MemberBusiness::search(const QString &) const{

    //da scrivere
}
