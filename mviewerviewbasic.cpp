#include "mviewerviewbasic.h"

MViewerViewBasic::MViewerViewBasic(QWidget* ptr)
    : MViewerView(ptr)
{

}

MViewerViewBasic::~MViewerViewBasic(){


}

void MViewerViewBasic::setToShow()const{

    getLayout()->addWidget(getCredential());
    getLayout()->addWidget(getBio());
    getLayout()->addWidget(getFriendships());
}
