#ifndef ADMINSEARCHMWMODEL_H
#define ADMINSEARCHMWMODEL_H


#include <QVector>

#include "datamember.h"
#include "smartmember.h"
#include "memberexecutive.h"

class AdminSearchMWModel
{
public:
    AdminSearchMWModel();

    ~AdminSearchMWModel();

    const QVector<QString> & cgetHobby()const;
    const QVector<QString> & cgetInterests()const;

    void addH(const QString &);
    void addI(const QString &);

    void wipeBuffers();

    const DataMember* getSearchResults()const;

    void setSearchResults(const DataMember &);
    void wipeSearchResults();

    const SmartMember & getMemberByNick(const QString &)const;


private:

    QVector<QString> hobbyBuffer;
    QVector<QString> interestsBuffer;

    const DataMember* searchResults;
};

#endif // ADMINSEARCHMWMODEL_H
