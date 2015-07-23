#include "mainwindow.h"
//#include <QApplication>
#include <QDate>


/*#include <iostream>
#include "profile.h"
#include "personal.h"
#include "experiences.h"*/

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
    */
}
