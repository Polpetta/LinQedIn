#ifndef USER_H
#define USER_H

#include "credentials.h"
#include "userdata.h"
#include <QString>
#include <QXmlStreamWriter>

#include <vector>

using std::vector;

class User
{
public:
    User(const Credentials & = Credentials(),
         const QString & = QString());

    virtual ~User();

    virtual UserData& search(const QString &) const =0;
    virtual void save (QXmlStreamWriter & ) const =0;
    virtual QString& getType();
    virtual const QString& cgetType()const;

    Credentials & getCredential();
    const Credentials & cgetCredential()const;

    void setCredential(const Credentials &);
    void setAccountValid(const bool &);

    bool isValid()const;

private:

    Credentials logCrd;
    bool valid;// = true;
    QString UserType;
    //ci andrà anche l'oggetto search qui che è ancora da creare
};

#endif // USER_H
