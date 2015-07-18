#ifndef PERSONAL_H
#define PERSONAL_H

#include <QDate>
#include <QString>

#include <list>

using std::list;

class Personal
{
public:
    Personal(QDate,
             QString,
             QString,
             QString,
             QString,
             bool);

    void addHobby(const QString &);
    void addInterest(const QString &);

    bool isSearching() const;

    int getAge() const;
    QDate getBirthday() const;

    void setName(const QString &);
    void setSurname(const QString &);
    void setPhone(const QString &);
    void setEmail(const QString &);
    void setBirthDay(const QDate &);

private:

    QDate birthDay;
    QString name;
    QString surname;
    QString phone;
    QString eMail;
    bool searchingJob;


    list<QString> hobby;
    list<QString> interests;
};

#endif // PERSONAL_H
