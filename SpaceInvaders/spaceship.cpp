#include "spaceship.h"



// Private constructor for spaceship
//SpaceShip::SpaceShip(int x, int y, int s, QPixmap m) : m_xcoord(x), m_ycoord(y), m_speed(s), m_mapObj(m)
//{}

SpaceShip::SpaceShip(int x, int y, int s, QPixmap m)
    : MovingObject(x,y,s,m) {}

SpaceShip::~SpaceShip() {}


void SpaceShip::moveLeft(){
    int position = -1 * getSpeed() + getX();
    setX(position);
}

void SpaceShip::moveRight(){
    int position = getSpeed() + getX();
    setX(position);
}


void SpaceShip::setX(int x){ m_xcoord = x; }

void SpaceShip::nextFrame() {}

void SpaceShip::draw(QPainter *painter){
    painter->drawPixmap(getX(), getY(), getPicture());
}
