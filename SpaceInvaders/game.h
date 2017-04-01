#ifndef GAME_H
#define GAME_H

#include "spaceship.h"
#include "bullet.h"

#include <QPainter>
#include <QTimer>



class Game
{
public:
    Game() {}
    ~Game() {}
    void addShip();
    void addBullet();
    void readConfig();

private:
    SpaceShip* m_ships[5];
    int m_shipIndex = 0;
    Bullet* m_bullets[10];
    int m_bullIndex = 0;  // TODO: fix this...

};



#endif // GAME_H
