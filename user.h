#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(const QString &, const QString &);

    virtual ~User();

    virtual User& search(const QString &) const =0;

private:
    QString nick;
    QString password;

    //ci andrà anche l'oggetto search qui che è ancora da creare
};

#endif // USER_H
