#include "memberexecutive.h"

MemberExecutive::MemberExecutive(const Credentials & crd,
                                 const QString & typ,
                                 const Profile & prf,
                                 const Friendships & frnd)
    : MemberBusiness(crd,typ,prf,frnd)

{}

MemberExecutive::~MemberExecutive(){}

UserData& MemberExecutive::search(const QString &) const{

    //da implementare
}
