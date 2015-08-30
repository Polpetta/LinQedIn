#include "msearchviewbasic.h"

MSearchViewBasic::MSearchViewBasic(QWidget* ptr)
    : MSearchView(ptr)
{

}


MSearchViewBasic::~MSearchViewBasic(){

}

void MSearchViewBasic::commitSearch()const{

    emit searchConfirm(MSearchView::getNameTex(),
                       MSearchView::getSurnameTex(),
                       MSearchView::getBirthDayTex());
}
