#include "viewerpair.h"

ViewerPair::ViewerPair()
{}

void ViewerPair::add(const QString &key, MSearchView *view){

    QMap<QString,MSearchView*>::insert(key, view);
}

void ViewerPair::rm(const QString & target){

    QMap<QString,MSearchView*>::remove(target);
}

ViewerPair::iterator::iterator(){}

ViewerPair::iterator::iterator(const QMap<QString, MSearchView *>::iterator & itr)
    : QMap<QString,MSearchView*>::iterator(itr)
{}

ViewerPair::iterator ViewerPair::begin(){

    return QMap<QString,MSearchView*>::begin();
}

ViewerPair::iterator ViewerPair::end(){

    return QMap<QString,MSearchView*>::end();
}

MSearchView* ViewerPair::operator [](const QString & key)const{

    return QMap<QString,MSearchView*>::operator [](key);
}


ViewerPair::const_iterator::const_iterator(){}

ViewerPair::const_iterator::const_iterator(const QMap<QString, MSearchView *>::const_iterator & itr)
    : QMap<QString,MSearchView*>::const_iterator(itr)
{}

ViewerPair::const_iterator ViewerPair::cbegin()const{

    return QMap<QString,MSearchView*>::begin();
}

ViewerPair::const_iterator ViewerPair::cend()const{

    return QMap<QString,MSearchView*>::end();
}

/*const MSearchView* ViewerPair::operator [](const QString & key)const{

    return QMap<QString,MSearchView*>::operator [](key);
}*/
