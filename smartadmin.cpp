#include "smartadmin.h"
#include "admin.h"

SmartAdmin::SmartAdmin(Admin* p)
    : punt(p)
{
    if (punt != 0)
        punt->getRef()++;

}

SmartAdmin::SmartAdmin(const SmartAdmin & cp)
    : SmartPtr(), punt(const_cast<Admin*>(cp.cgetPunt()))
{
    if (punt != 0)
        punt->getRef()++;

}

SmartAdmin::~SmartAdmin(){

    if (punt != 0){

        //cancellazione logica
        punt->getRef()--;

        if (punt->cgetRef() == 0)
            delete punt; //cancellaizone fisica
    }
}

SmartAdmin& SmartAdmin::operator =(const SmartAdmin & as){

    if (this != &as){
        Admin* tmp = punt;

        punt = const_cast<Admin*>(as.cgetPunt());

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

bool SmartAdmin::operator ==(const SmartAdmin & comp)const{

    return punt == comp.cgetPunt();
}

bool SmartAdmin:: operator != (const SmartAdmin & comp)const{

    return punt != comp.cgetPunt();
}

Admin& SmartAdmin::operator *()const{

    return *punt;
}

Admin* SmartAdmin::operator ->()const{

    return punt;
}

Admin* & SmartAdmin::getPunt(){

    return punt;
}

const Admin* SmartAdmin::cgetPunt()const{

    return punt;
}
