#ifndef SMARTADMIN_H
#define SMARTADMIN_H

#include "smartptr.h"

class Admin;

class SmartAdmin : public SmartPtr
{
public:
    SmartAdmin(Admin* = nullptr);
    SmartAdmin(const SmartAdmin &);
    ~SmartAdmin();

    SmartAdmin& operator= (const SmartAdmin &);
    bool operator== (const SmartAdmin&)const;
    bool operator!= (const SmartAdmin&)const;
    Admin& operator* ()const;
    Admin* operator->()const;

    Admin* & getPunt();
    const Admin* cgetPunt()const;

private:
    Admin* punt;
};

#endif // SMARTADMIN_H
