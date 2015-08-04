#include "memberbusiness.h"

MemberBusiness::MemberBusiness(const Credentials & crd,
                               const QString & typ,
                               const Profile & prf,
                               const Friendships & frnd,
                               Database * ptr)
    : MemberBasic (crd,typ,prf,frnd,ptr)
{}

MemberBusiness::~MemberBusiness() {}

const DataMember& MemberBusiness::search(const Profile & target) const{

    const QString & name = target.cgetPersonal().cgetBio().getName();
    const QString & surn = target.cgetPersonal().cgetBio().getSurname();

    const Hobby & hbb = target.cgetPersonal().cgetHobby();
    const Interests & intr = target.cgetPersonal().cgetInterests();

    Bio searchBase (name, surn);

    Personal searchBusiness (searchBase,hbb,intr);

    return getDb()->select(Profile(searchBusiness));

}
