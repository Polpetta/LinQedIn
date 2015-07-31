#ifndef USER_H
#define USER_H

#include "credentials.h"
#include "userdata.h"
#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include <vector>

//altrimenti il compilatore va in loop.
class UserData;


using std::vector;

class User
{
public:
    User(const Credentials & = Credentials(),
         const QString & = QString());

    virtual ~User();

    virtual UserData& search(const QString &) const =0;

    virtual void save (QXmlStreamWriter & ) const =0;
    virtual void saveBack (QXmlStreamWriter &) const =0;
    virtual void load (QXmlStreamReader & ) =0;
    virtual void loadBack (QXmlStreamReader & ) =0;


    virtual QString& getType();
    virtual const QString& cgetType()const;

    Credentials & getCredential();
    const Credentials & cgetCredential()const;

    void setCredential(const Credentials &);
    void setAccountValid(const bool &);
    void setAccountType(const QString &);

    bool isValid()const;

    int & getRef();
    const int & cgetRef()const;

private:

    Credentials logCrd;
    bool valid;// = true;
    QString UserType;
    int ref;
    //ci andrà anche l'oggetto search qui che è ancora da creare
};

#endif // USER_H
