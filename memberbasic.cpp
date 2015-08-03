#include "memberbasic.h"

MemberBasic::MemberBasic(const Credentials & crd,
                         const QString & typ,
                         const Profile & prf,
                         const Friendships & frnd)
    : Member(crd,typ,prf,frnd)
{}

MemberBasic::~MemberBasic(){}

DataMember& MemberBasic::search(const QString & target) const{

    //DEFINITA SOLO PER PROVA, MANCA ANCORA DA SCRIVERE LA CLASSE
    //SEARCH!!!

}


