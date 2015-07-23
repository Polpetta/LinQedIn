#ifndef BIO_H
#define BIO_H

#include<QDate>
#include<QString>

class Bio
{
public:
    Bio(const QDate & = QDate(),
        const QString & = QString(),
        const QString & = QString(),
        const QString & = QString(),
        const QString & = QString()
            );

    QString getName()const;
    QString getSurname()const;
    QString getPhone()const;
    QString getMail()const;

    int getAge() const;
    QDate getBirthday() const;

    void setBirthday(const QDate &);
    void setName (const QString &);
    void setSurname (const QString &);
    void setPhone (const QString &);
    void setMail (const QString &);

private:
    QDate birthDay;
    QString name;
    QString surname;
    QString phone;
    QString eMail;

};

#endif // BIO_H
