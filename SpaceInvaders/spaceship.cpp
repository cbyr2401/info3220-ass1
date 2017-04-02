#include "spaceship.h"


// Private constructor for spaceship
SpaceShip::SpaceShip(int x, int y, int speed, QPixmap map)
    :m_xcoord(x), m_ycoord(y), m_speed(speed), m_mapObj(map) {}

// Public destructor
SpaceShip::~SpaceShip() {}

// function to move the spaceship to the left of the screen
//  by m_speed pixels.
void SpaceShip::moveLeft(){
    int position = -1 * getSpeed() + getX();
    setX(position);
}

// function to move the spaceship to the right of the screen
//  by m_speed pixels.
void SpaceShip::moveRight(){
    int position = getSpeed() + getX();
    setX(position);
}

// draw the spaceship onto the display via QPainter.
void SpaceShip::draw(QPainter &painter){
    painter.drawPixmap(getX(), getY(), getPicture());
}

// setter for "x" value which changes constantly
void SpaceShip::setX(int x){ m_xcoord = x; }
