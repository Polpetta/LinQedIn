#ifndef PERSONAL_H
#define PERSONAL_H

#include <QDate>
#include <QString>

#include "hobby.h"
#include "interests.h"
#include "experiences.h" //le esperienze fanno parte di personal?



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
    void rmHobby(const QString &);


    void addInterest(const QString &);
    void rmInterest(const QString &);

    void addExperiences(const Event &);
    void rmExperiences(const Event &);

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


    Hobby hbb;
    Interests ntr;
    Experiences exp;
};

#endif // PERSONAL_H
