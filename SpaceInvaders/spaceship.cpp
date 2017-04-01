#include "spaceship.h"



// Private constructor for spaceship
//SpaceShip::SpaceShip(int x, int y, int s, QPixmap m) : m_xcoord(x), m_ycoord(y), m_speed(s), m_mapObj(m)
//{}

void SpaceShip::moveLeft(){
    int position = -1 * getSpeed() + getX();
    setX(position);
}

void SpaceShip::moveRight(){
    int position = getSpeed() + getX();
    setX(position);
}


void SpaceShip::setX(int x){ m_xcoord = x; }
