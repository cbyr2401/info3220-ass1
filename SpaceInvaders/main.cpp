#include "dialog.h"
#include <QApplication>
#include <battlesphere.h>
#include "gameengine.h"

using namespace si;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //BattleSphere w;
    //w.show();

    GameEngine w;

    std::cout << "READY TO SHOW WINDOW" << std::endl;

    w.show();

    std::cout << "POST SHOW WINDOW" << std::endl;


    return a.exec();
}
