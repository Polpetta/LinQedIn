#include "interests.h"

Interests::Interests()
{}

Interests::Interests (const QVector<QString> & nInterests)
    : QList<QString> (QList<QString>::fromVector(nInterests))
{}

void Interests::add(const QString & newInterests){

    QList<QString>::push_back(newInterests);
}

void Interests::rm(const QString & target){

    QList <QString>::removeAll(target);
}

void Interests::purgeEquals(){

    QList<QString>::const_iterator it1;
    QList<QString>::iterator it2;

    for (it1 = QList<QString>::cbegin();
         it1 != QList<QString>::cend();
         ++it1){

        const QString & target = *it1;

        for (it2 = QList<QString>::begin();
             it2 != QList<QString>::end();
             ++it2){

            if (it1 != it2 &&
                    QString::compare(target, *it2, Qt::CaseInsensitive) == 0){

                QList<QString>::erase(it2);
            }
        }
    }
}

Interests::iterator::iterator() {}

Interests::iterator::iterator(const QList<QString>::iterator & itr)
    : QList<QString>::iterator(itr) {}

Interests::iterator Interests::begin(){

    return QList<QString>::begin();
}

Interests::iterator Interests::end(){

    return QList<QString>::end();
}

QString & Interests::operator [] (const Interests::iterator & it) const{

    return *it;
}

Interests::const_iterator::const_iterator() {}

Interests::const_iterator::const_iterator(const QList::const_iterator & itr)
    :QList<QString>::const_iterator(itr) {}

Interests::const_iterator Interests::cbegin() const{

    return QList<QString>::begin();
}

Interests::const_iterator Interests::cend() const{

    return QList<QString>::end();
}

const QString & Interests::operator [] (const Interests::const_iterator & it) const{

    return *it;
}


bool Interests::operator==(const Interests & as)const{

    return QList<QString>::operator ==(as);
}

bool Interests::operator!=(const Interests & as)const{

    return QList<QString>::operator !=(as);
}


bool Interests::contains(const QString &target) const{

    return QList<QString>::contains(target);
}


int Interests::size()const{

    return QList<QString>::size();
}

QVector<QString> Interests::toVector()const{

    return QList<QString>::toVector();
}
