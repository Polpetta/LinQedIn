#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include<QString>

class Credentials
{
public:
    Credentials(const QString & = QString());

    const QString & getCredential()const;

private:

    QString nick;
};

#endif // CREDENTIALS_H
