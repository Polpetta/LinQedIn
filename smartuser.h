#ifndef SMARTUSER_H
#define SMARTUSER_H

#include "user.h"

//altrimenti il compilatore va in loop.
class User;

class SmartUser
{
public:
    SmartUser(User* = NULL); //costruttore
    SmartUser(const SmartUser &); //costruttore di copia
    ~SmartUser(); //distruttore

    //operandi
    SmartUser& operator= (const SmartUser &); //assegnazione
    bool operator==(const SmartUser&)const; //uguaglianza
    bool operator!=(const SmartUser&)const; //disuguaglianza
    User& operator* ()const; //dereferenziazione
    User* operator->()const; //accesso a membro

    User* & getPunt();
    const User* cgetPunt()const; //non riesco a passarlo per rif (?!)

private:
    User* punt;
};

#endif // SMARTUSER_H
