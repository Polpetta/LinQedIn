#ifndef USER_H
#define USER_H


#include <QString>

class Database;

class User
{
protected:

    User(const QString & = QString(),
         Database* = nullptr);
    User(const User&) =default;

public:

    virtual ~User();

    virtual QString& getType();
    virtual const QString& cgetType()const;

    void setAccountValid(const bool &);
    void setAccountType(const QString &);
    void setDb(Database *);

    bool isValid()const;

    int & getRef();
    const int & cgetRef()const;

    Database* getDb()const;

private:


    bool valid;// = true;
    QString UserType;
    int ref;
    Database* db;
};

#endif // USER_H
