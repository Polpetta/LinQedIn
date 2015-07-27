#include "smartuser.h"

SmartUser::SmartUser(User* p)
    : punt(p)
{
    if (punt != 0)
        punt->getRef()++;
}

SmartUser::SmartUser(const SmartUser & cp)
    : punt(const_cast<User*>(cp.cgetPunt()))
{
    if (punt != 0)
        punt->getRef()++;

}

SmartUser::~SmartUser(){

    if (punt != 0){

        //cancellazione logica
        punt->getRef()--;

        if (punt->cgetRef() == 0)
            delete punt; //cancellazione fisica
    }
}

SmartUser& SmartUser::operator = (const SmartUser & as){

    if (this != &as){
        User* tmp = punt;

        punt = const_cast<User*>(as.cgetPunt());

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

bool SmartUser::operator ==(const SmartUser & comp)const{

    return punt == comp.cgetPunt();
}

bool SmartUser::operator !=(const SmartUser & comp)const{

    return punt != comp.cgetPunt();
}

User& SmartUser::operator *()const{

    return *punt;
}

User* SmartUser::operator ->()const{

    return punt;
}



User* & SmartUser::getPunt(){

    return punt;
}

const User* SmartUser::cgetPunt()const{

    return punt;
}
