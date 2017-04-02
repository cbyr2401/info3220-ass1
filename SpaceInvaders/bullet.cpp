#include "bullet.h"


void Bullet::advance(){
    int value = -1 * getSpeed() + getY();
    setY(value);
}

void Bullet::setY(int y) { m_ycoord = y; }


// called every new frame (apparently)
void Bullet::nextFrame(){
    if(m_ycoord <= -100){
        delete this;
    }else{
        advance();
    }
    //update();
}

void Bullet::draw(QPainter *painter){
    painter->drawPixmap(getX(), getY(), getPicture());
}
