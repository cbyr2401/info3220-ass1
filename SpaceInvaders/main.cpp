#include "dialog.h"
#include <QApplication>
#include <battlesphere.h>

using namespace si;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BattleSphere w;
    w.show();

//    for(int memes=0; memes < 1000; memes++){
//        w.nextFrame();
//    }

    return a.exec();
}
