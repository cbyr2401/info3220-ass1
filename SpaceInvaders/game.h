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
    void updateBullets();
    void step(std::string instruction);
    void update(QPainter &painter);
    SpaceShip getSpaceShip() { return m_ship; }
    Bullet getBullet() { return m_bullet; }

private:
    //SpaceShip* m_ships[5];  << for multiple ships
    //Bullet* m_bullets[10];  << for multiple bullets
    SpaceShip m_ship;
    int m_shipIndex = 0;    //<< for multiple ships
    Bullet m_bullet;
    int m_bullIndex = 0;    //<< for multiple bullets
    Configuration m_config;

};



#endif // GAME_H
