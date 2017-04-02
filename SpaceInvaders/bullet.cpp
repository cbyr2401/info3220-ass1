#include "bullet.h"


// Private constructor for Bullet
Bullet::Bullet(int x, int y, int speed, QPixmap map, QMediaPlayer* p)
    :m_xcoord(x), m_ycoord(y), m_speed(speed), m_mapObj(map),
        m_player(p)
{
    // play the sound once when the bullet becomes live.
    m_player->play();
}

// Public destructor
Bullet::~Bullet() {}

// moves the bullet by m_speed pixels on the y-axis
void Bullet::advance(){
    if(m_ycoord <= -100){
        //delete this;
    }else{
        int value = -1 * getSpeed() + getY();
        setY(value);
    }
}

// draw the bullet onto the display via QPainter
void Bullet::draw(QPainter &painter){
    painter.drawPixmap(getX(), getY(), getPicture());
}

// setter for y value since it is constantly changing
void Bullet::setY(int y) { m_ycoord = y; }
