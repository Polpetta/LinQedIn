#ifndef ADMINSEARCHMWMODEL_H
#define ADMINSEARCHMWMODEL_H


#include <QVector>

class AdminSearchMWModel
{
public:
    AdminSearchMWModel();

    const QVector<QString> & cgetHobby()const;
    const QVector<QString> & cgetInterests()const;

    void addH(const QString &);
    void addI(const QString &);

    void wipeBuffers();


private:

    QVector<QString> hobbyBuffer;
    QVector<QString> interestsBuffer;
};

#endif // ADMINSEARCHMWMODEL_H
