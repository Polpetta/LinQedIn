#include "mviewerviewexecutive.h"

MViewerViewExecutive::MViewerViewExecutive(QWidget* ptr)
    : MViewerViewBusiness(ptr)
{

}

MViewerViewExecutive::~MViewerViewExecutive(){


}

void MViewerViewExecutive::setToShow()const{

    MViewerViewBusiness::setToShow();

    getLayout()->addWidget(getExperiences());
}
