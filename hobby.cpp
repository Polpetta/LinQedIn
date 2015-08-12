#include "hobby.h"

Hobby::Hobby()
{}

Hobby::Hobby(const QVector<QString> & nHobby)
    : QList<QString>(QList<QString>::fromVector(nHobby))
{}

void Hobby::add(const QString & newHobby){

    QList<QString>::push_back(newHobby);
}

void Hobby::rm(const QString & target){

    QList<QString>::removeAll(target);
}

void Hobby::purgeEquals(){

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

Hobby::iterator::iterator() {}

Hobby::iterator::iterator(const QList<QString>::iterator & itr)
    : QList<QString>::iterator(itr) {}

Hobby::iterator Hobby::begin(){

    return QList<QString>::begin();
}

Hobby::iterator Hobby::end(){

    return QList<QString>::end();
}

QString & Hobby::operator [] (const Hobby::iterator & it) const{

    return *it;
}


Hobby::const_iterator::const_iterator() {}

Hobby::const_iterator::const_iterator(const QList<QString>::const_iterator & itr)
    : QList<QString>::const_iterator(itr) {}

Hobby::const_iterator Hobby::cbegin() const{

    return QList<QString>::begin();
}

Hobby::const_iterator Hobby::cend() const{

    return QList<QString>::end();
}

const QString& Hobby::operator [](const Hobby::const_iterator & it) const{
    return *it;
}


bool Hobby::operator ==(const Hobby & as)const{

    return QList<QString>::operator ==(as);
}

bool Hobby::operator !=(const Hobby & as)const{

    return QList<QString>::operator !=(as);
}


bool Hobby::contains(const QString & target) const{

    return QList<QString>::contains(target);
}


int Hobby::size()const{

    return QList<QString>::size();
}

QVector<QString> Hobby::toVector()const{

    /*
     * Ricalco fedelmente la funzione, anche se ne eseguo una copia
     */
    return QList<QString>::toVector();
}
