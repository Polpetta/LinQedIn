#ifndef SMARTMEMBER_H
#define SMARTMEMBER_H

#include "smartptr.h"

class Member;

class SmartMember : public SmartPtr
{
public:
    SmartMember(Member* = nullptr);
    SmartMember(const SmartMember &);
    ~SmartMember();

    SmartMember& operator= (const SmartMember &);
    bool operator== (const SmartMember&)const;
    bool operator!= (const SmartMember&)const;
    Member& operator* ()const;
    Member* operator->()const;

    Member* & getPunt();
    const Member* cgetPunt()const;

private:
    Member* punt;
};

#endif // SMARTMEMBER_H
