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

    int getAge() const;
    QDate getBirthday() const;

    void setBio (const Bio &);

private:
    QDate birthDay;
    QString name;
    QString surname;
    QString phone;
    QString eMail;

};

#endif // BIO_H
