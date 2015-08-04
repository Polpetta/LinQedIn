#ifndef USER_H
#define USER_H


//#include "userdata.h"
#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include <vector>

#include "credentials.h"
#include "datamember.h"


//altrimenti il compilatore va in loop.
class DataMember;


using std::vector;

class User
{
public:
    User(const QString & = QString());

    virtual ~User();

    virtual DataMember& search(const QString &) const =0;

    virtual QString& getType();
    virtual const QString& cgetType()const;

    void setAccountValid(const bool &);
    void setAccountType(const QString &);

    bool isValid()const;

    int & getRef();
    const int & cgetRef()const;

private:


    bool valid;// = true;
    QString UserType;
    int ref;
    //ci andrà anche l'oggetto search qui che è ancora da creare
};

#endif // USER_H
