#include "smartmember.h"
#include "member.h"

SmartMember::SmartMember(Member* p)
    : punt(p)
{
    if (punt != 0)
        punt->getRef()++;

}

SmartMember::SmartMember(const SmartMember & cp)
    : SmartPtr(), punt(const_cast<Member*>(cp.cgetPunt()))
{
    if (punt != 0)
        punt->getRef()++;

}

SmartMember::~SmartMember(){

    if (punt != 0){

        //cancellazione logica
        punt->getRef()--;

        if (punt->cgetRef() == 0)
            delete punt; //cancellazione fisica
    }
}

SmartMember& SmartMember::operator = (const SmartMember & as){

    if (this != &as){
        Member* tmp = punt;

        punt = const_cast<Member*>(as.cgetPunt());

        if (punt != 0)
            punt->getRef()++;

        if (tmp != 0){

            tmp->getRef()--;
            if (tmp->cgetRef() == 0)
                delete tmp;
        }
    }

    return *this;
}

bool SmartMember::operator ==(const SmartMember & comp)const{

    return punt == comp.cgetPunt();
}

bool SmartMember:: operator !=(const SmartMember & comp)const{

    return punt != comp.cgetPunt();
}

Member& SmartMember::operator *()const{

    return *punt;
}

Member* SmartMember::operator ->()const{

    return punt;
}


Member* & SmartMember::getPunt(){

    return punt;
}

const Member* SmartMember::cgetPunt()const{

    return punt;
}
