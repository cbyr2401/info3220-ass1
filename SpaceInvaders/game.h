#ifndef GAME_H
#define GAME_H

#include "spaceship.h"
#include "bullet.h"
#include "configuration.h"

#include <QPainter>
#include <QTimer>



class Game
{
public:
    Game(Configuration config);
    Game() {}
    ~Game() {}
    void addShip();
    void addBullet(int y);
    void readConfig(std::string path);
    void updateBullets();
    void step(std::string instruction);
    void update(QPainter *painter);

private:
    SpaceShip* m_ships[5];
    int m_shipIndex = 0;
    Bullet* m_bullets[10];
    int m_bullIndex = 0;  // TODO: fix this...
    Configuration m_config;


};



#endif // GAME_H
