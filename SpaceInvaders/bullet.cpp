#include "bullet.h"



Bullet::Bullet(int x, int y, int speed, QPixmap map, QMediaPlayer* p)
    :m_xcoord(x), m_ycoord(y), m_speed(speed), m_mapObj(map),
        m_player(p)
{
    m_player->play();

    // set up the timer
    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    //timer->start(32);
}

void Bullet::advance(){
    if(m_ycoord <= -100){
        //delete this;
    }else{
        int value = -1 * getSpeed() + getY();
        setY(value);
    }
}

void Bullet::setY(int y) { m_ycoord = y; }


void Bullet::draw(QPainter &painter){
    painter.drawPixmap(getX(), getY(), getPicture());
}

//void Bullet::nextFrame(){
//    advance();
//}
