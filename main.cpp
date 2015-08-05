#include "mainwindow.h"
//#include <QApplication>
#include <QDate>


#include <iostream>
#include "profile.h"
#include "personal.h"
#include "experiences.h"

#include "user.h"
#include "memberbasic.h"
#include "dbonxml.h"
#include "database.h"
#include "smartmember.h"
#include "credentials.h"
#include "datamember.h"

int main(int argc, char *argv[])
{


    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();

    QDate nascita1(1994,8,27);
    QDate nascita2(2001,5,15);

    Bio b1("Super",
           "Man",
           nascita1,
           "3204029401",
           "poloniodavide@gmail.com");

    Bio b2("Gino",
           "Pino",
           nascita2,
           "3205437306",
           "giangiala@gmail.com");


    Personal prova1(b1);
    Personal prova2(b2);

    prova1.getHobby().add("Computer");
    prova1.getHobby().add("Giardinaggio");

    prova2.getHobby().add("Giocare");

    prova1.getInterests().add("SysAdmin");

    prova2.getInterests().add("Dormire");

    std::cout<<"Fatto personal"<<std::endl;

    Experiences exp;

    Event e1 (QDate(2009,8,24),
              QDate(2010,9,12),
              "Prima scorreggia",
              "A casa mia");

    Event e2 (QDate(2011,6,5),
              QDate(2012,8,1),
              "Giro in bici",
              "Parco regionale dei Colli Euganei");

    exp.add(e1);
    exp.add(e2);

    Profile profilo1 (prova1,
                     exp);

    Profile profilo2 (prova2);

    std::cout<<"Fatto profile"<<std::endl;

    /*Experiences::const_iterator it;

    for (it = profilo.cgetExperiences().cbegin(); it != profilo.cgetExperiences().cend(); ++it){

        //std::cout<<"Sto iterando"<<std::endl;

        std::cout << profilo.cgetExperiences()[it].getEvent().toStdString() <<std::endl;
    }*/

    std::cout<<"Fine"<<std::endl;


    Credentials nick ("davide");

    Database* pdb = new DBonXml("prova");

    SmartMember u1 = new MemberBasic(nick,
                                   "Basic",
                                   profilo1,
                                     Friendships(),
                                     pdb);

    Credentials nick2 ("gino");

    Friendships n2;

    n2.add(u1->cgetCredential().getCredential());

    SmartMember u2 = new MemberBasic(nick2,
                                   "Basic",
                                   profilo2,
                                   n2,
                                     pdb);

    Admin test("Admin");

    test.changeMemberType(u2, "Executive");

    std::cout<<"Dopo promozione: "<<u2->cgetType().toStdString()<<std::endl;


    u1->getFriendships().add("gino");
    std::cout<<"Aggiunta amicizia"<<std::endl;

    test.changeMemberType(u2, "Business");

    SmartMember u3 = new MemberExecutive(nick2,
                                         "Executive",
                                         profilo1,
                                         n2,
                                         pdb);

    pdb->getDb().add(u1);
    std::cout<<"Aggiunto uno"<<std::endl;
    pdb->getDb().add(u2);
    std::cout<<"Aggiunto due"<<std::endl;
    pdb->getDb().add(u3);
    std::cout<<"Aggiunto tre (non dovrebbe essere aggiunto)"<<std::endl;
    pdb->save();


    std::cout<<"Scritto"<<std::endl;


    Profile sProva (u1->cgetProfile());
    const DataMember & provas1 = u2->search(sProva);

    DataMember::const_iterator resultS;

    std::cout<<"RISULTATI RICERCA"<<std::endl;
    for (resultS = provas1.cbegin(); resultS != provas1.cend(); ++resultS){

        const Profile & res = (*resultS)->cgetProfile();
        const Bio & res1 = res.cgetPersonal().cgetBio();

        std::cout<<res1.getName().toStdString()<<std::endl;
        std::cout<<res1.getSurname().toStdString()<<std::endl;
    }

    std::cout<<"Size prima: "<<pdb->cgetDb().size()<<std::endl;
    pdb->getDb().clear();
    std::cout<<"Size dopo: "<<pdb->cgetDb().size()<<std::endl;

    pdb->load();
    std::cout<<"Size ora: "<<pdb->cgetDb().size()<<std::endl;

}
