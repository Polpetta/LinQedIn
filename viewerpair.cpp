#include "viewerpair.h"

ViewerPair::ViewerPair()
{}

void ViewerPair::add(const QString &key, viewCollection* view){

    QMap<QString,viewCollection*>::insert(key, view);
}

void ViewerPair::rm(const QString & target){

    QMap<QString,viewCollection*>::remove(target);
}

ViewerPair::iterator::iterator(){}

ViewerPair::iterator::iterator(const QMap<QString, viewCollection*>::iterator & itr)
    : QMap<QString,viewCollection*>::iterator(itr)
{}

ViewerPair::iterator ViewerPair::begin(){

    return QMap<QString,viewCollection*>::begin();
}

ViewerPair::iterator ViewerPair::end(){

    return QMap<QString,viewCollection*>::end();
}

viewCollection* ViewerPair::operator [](const QString & key)const{

    return QMap<QString,viewCollection*>::operator [](key);
}


ViewerPair::const_iterator::const_iterator(){}

ViewerPair::const_iterator::const_iterator(const QMap<QString, viewCollection*>::const_iterator & itr)
    : QMap<QString,viewCollection*>::const_iterator(itr)
{}

ViewerPair::const_iterator ViewerPair::cbegin()const{

    return QMap<QString,viewCollection*>::begin();
}

ViewerPair::const_iterator ViewerPair::cend()const{

    return QMap<QString,viewCollection*>::end();
}
