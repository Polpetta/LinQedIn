#ifndef SMARTPTR_H
#define SMARTPTR_H


class SmartPtr
{

protected:
    SmartPtr() =default;
    SmartPtr(const SmartPtr&) =default;

public:
    virtual ~SmartPtr();
};

#endif // SMARTPTR_H
