#ifndef MEMBERSEARCHMWMODEL_H
#define MEMBERSEARCHMWMODEL_H

#include <QVector>

#include "membermwviewercontroller.h"

#include "datamember.h"
#include "smartmember.h"
#include "memberexecutive.h"

class MemberSearchMWModel
{
public:
    MemberSearchMWModel();

    ~MemberSearchMWModel();

    const QVector<QString> & cgetHobby()const;
    const QVector<QString> & cgetInterests()const;

    void addH(const QString &);
    void addI(const QString &);

    void wipeBuffers();

    void setSearchResults(const DataMember &);
    void wipeSearchResults();

    const SmartMember & getMemberByNick(const QString &)const;

    const DataMember* getSearchResults()const;

    const QString & cgetType()const;
    void setType(const QString &);

    MemberMWViewerController* getProfileViewer()const;

private:

    QVector<QString> hobbyBuffer;
    QVector<QString> interestsBuffer;

    const DataMember* lastResults;

    QString typeSearch;

    MemberMWViewerController* profileViewer;

};

#endif // MEMBERSEARCHMWMODEL_H
