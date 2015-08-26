#include "mviewerviewbusiness.h"

MViewerViewBusiness::MViewerViewBusiness(QWidget* ptr)
    : MViewerViewBasic(ptr)
{

}

MViewerViewBusiness::~MViewerViewBusiness(){


}

void MViewerViewBusiness::setToShow()const{

    MViewerViewBasic::setToShow(); //funzionalità di basic

    getLayout()->addWidget(getHobby());
    getLayout()->addWidget(getInterests());
}
