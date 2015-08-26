#include "admin.h"

Admin::Admin(const QString & typ,
             Database * ptr)
    : User (typ, ptr)
{}

Admin::~Admin() {}

DataMember & Admin::search (const Profile & target)const{

    return getDb()->select(target);
}

SmartMember & Admin::search(const QString & target) const{

    return getDb()->select(target);
}

void Admin::addMember(const SmartMember & newUser) const{

    getDb()->getDb().add(newUser);
}

void Admin::rmMember (const SmartMember & target) const{

    getDb()->getDb().rm(target);
}

void Admin::changeMemberType(SmartMember & oldMember, const QString &newType)const{

    if (oldMember->cgetType() != newType){

        SmartMember newMember;

        if (newType == "Basic"){

            newMember = new MemberBasic(oldMember->cgetCredential(),
                                        newType,
                                        oldMember->cgetProfile(),
                                        oldMember->cgetFriendships(),
                                        oldMember->getDb());
        }
        else if (newType == "Business"){

            newMember = new MemberBusiness(oldMember->cgetCredential(),
                                           newType,
                                           oldMember->cgetProfile(),
                                           oldMember->cgetFriendships(),
                                           oldMember->getDb());
        }
        else if (newType == "Executive"){

            newMember = new MemberExecutive(oldMember->cgetCredential(),
                                            newType,
                                            oldMember->cgetProfile(),
                                            oldMember->cgetFriendships(),
                                            oldMember->getDb());
        }

        //disattivo l'account "vecchio"
        oldMember->setAccountValid(false);

        oldMember = newMember;
    }
}
