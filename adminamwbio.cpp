#include "adminamwbio.h"

AdminAMWBio::AdminAMWBio(QWidget* ptr)
    : QWizardPage (ptr)
{

    setTitle( tr ("Inserimento campi" ));

    QLabel* nick = new QLabel ( tr ("NickName") );
    QLineEdit* nickEdit = new QLineEdit;

    QLabel* name = new QLabel ( tr("Nome") );
    QLineEdit* nameEdit = new QLineEdit;

    QLabel* surname = new QLabel( tr("Cognome") );
    QLineEdit* surnameEdit = new QLineEdit;

    QLabel* birthDay = new QLabel( tr("Data di nascita (dd-mm-yyyy)") );
    QLineEdit* birthDayEdit = new QLineEdit;

    QLabel* phone = new QLabel( tr("Telefono") );
    QLineEdit* phoneEdit = new QLineEdit;

    QLabel* eMail = new QLabel( tr("e-Mail") );
    QLineEdit* eMailEdit = new QLineEdit;

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(nick, 0, 0);
    layout->addWidget(nickEdit, 0, 1);

    layout->addWidget(name, 1, 0);
    layout->addWidget(nameEdit, 1, 1);

    layout->addWidget(surname, 2, 0);
    layout->addWidget(surnameEdit, 2, 1);

    layout->addWidget(birthDay, 3, 0);
    layout->addWidget(birthDayEdit, 3, 1);

    layout->addWidget(phone, 4, 0);
    layout->addWidget(phoneEdit, 4, 1);

    layout->addWidget(eMail, 5, 0);
    layout->addWidget(eMailEdit, 5 ,1);

    registerField("nick*", nickEdit);
    registerField("name*", nameEdit);
    registerField("surname*", surnameEdit);
    registerField("birthDay*", birthDayEdit);
    registerField("phone", phoneEdit);
    registerField("eMail", eMailEdit);

    setLayout(layout);

}

AdminAMWBio::~AdminAMWBio(){


}

const QString & AdminAMWBio::cgetField(const QString & field)const{

    QString * res = new QString (QWizardPage::field(field).toString());

    return *res;
}
