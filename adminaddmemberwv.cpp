#include "adminaddmemberwv.h"

AdminAddMemberWV::AdminAddMemberWV(QWidget * parent)
    : QWizard(parent)
{

    AdminAMWIntro* intro = new AdminAMWIntro;
    AdminAMWBio* bio = new AdminAMWBio;
    AdminAMWHobby* hobby = new AdminAMWHobby;
    AdminAMWInterests* interests = new AdminAMWInterests;
    AdminAMWEnd* end = new AdminAMWEnd;

    addPage(intro);
    addPage(bio);
    addPage(hobby);
    addPage(interests);
    addPage(end);

    field("name");

    setWindowTitle( tr("Wizard Aggiunta Iscritto") );

    setFixedSize( sizeHint() );

}

AdminAddMemberWV::~AdminAddMemberWV(){


}
