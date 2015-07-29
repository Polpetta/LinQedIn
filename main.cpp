#include "mainwindow.h"
//#include <QApplication>
#include <QDate>


#include <iostream>
#include "profile.h"
#include "personal.h"
#include "experiences.h"

/*#include "user.h"
#include "memberbasic.h"
#include "dbonxml.h"
#include "database.h"
#include "smartuser.h"
#include "credentials.h"*/

int main(int argc, char *argv[])
{


    /*//QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();

    QDate nascita(1994,8,27);

    Bio b1(nascita,
           "Davide",
           "Polonio",
           "3204961582",
           "poloniodavide@gmail.com");

    Personal prova(b1);

    prova.getHobby().add("Computer");
    prova.getHobby().add("Giardinaggio");

    prova.getInterests().add("SysAdmin");

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

    Profile profilo (prova,
                     exp);

    std::cout<<"Fatto profile"<<std::endl;

    Experiences::const_iterator it;

    for (it = profilo.cgetExperiences().cbegin(); it != profilo.cgetExperiences().cend(); ++it){

        //std::cout<<"Sto iterando"<<std::endl;

        std::cout << profilo.cgetExperiences()[it].getEvent().toStdString() <<std::endl;
    }

    std::cout<<"Fine"<<std::endl;


    Credentials nick ("davide");

    Database* pdb = new DBonXml("prova");

    SmartUser u1 = new MemberBasic(nick,
                                   "Basic",
                                   profilo);

    Credentials nick2 ("gino");

    Friendships n2;

    n2.add(u1);

    SmartUser u2 = new MemberBasic(nick2,
                                   "Basic",
                                   profilo,
                                   n2);

    pdb->getDb().add(u1);
    pdb->getDb().add(u2);
    pdb->save();

    std::cout<<"Scritto"<<std::endl; */

}
