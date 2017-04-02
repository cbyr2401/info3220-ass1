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
    w.show();

    return a.exec();
}
