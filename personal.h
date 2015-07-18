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

    void addHobby(QString);
    void addInterests(QString);

    bool isSearching() const;

    int getAge() const;
    QDate getBirthday() const;

    void setName(QString);
    void setSurname(QString);
    void setPhone(QString);
    void setEmail(QString);
    void setBirthDay(QDate);

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
