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
    void addShip(Configuration config);
    void addBullet(int x);
    void readConfig(std::string path);
    void updateBullets();
    void step(std::string instruction);
    void update(QPainter &painter);
    SpaceShip getSpaceShip() { return m_ship; }
    Bullet getBullet() { return m_bullet; }

private:
    //SpaceShip* m_ships[5];
    SpaceShip m_ship;
    int m_shipIndex = 0;
    //Bullet* m_bullets[10];
    Bullet m_bullet;
    int m_bullIndex = 0;  // TODO: fix this...
    Configuration m_config;


};



#endif // GAME_H
