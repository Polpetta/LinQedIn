#include "memberexecutive.h"

MemberExecutive::MemberExecutive(const Credentials & crd,
                                 const QString & typ,
                                 const Profile & prf,
                                 const Friendships & frnd,
                                 Database * ptr)
    : MemberBusiness(crd,typ,prf,frnd,ptr)

{}

MemberExecutive::~MemberExecutive(){}

const DataMember& MemberExecutive::search(const Profile &target) const{

    //Essendo un business, butto tutto nella ricerca!
    return getDb()->select(target);
}
