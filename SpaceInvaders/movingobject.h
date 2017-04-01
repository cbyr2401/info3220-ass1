#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H


#include <QPainter>
#include <QPixmap>
#include <QString>

#include <iostream>



class MovingObject
{
public:
    MovingObject(int x, int y, int speed, QPixmap map)
        :m_xcoord(x), m_ycoord(y), m_speed(speed), m_mapObj(map) {}

    ~MovingObject() {}
    class Builder;
    int getX() { return m_xcoord; }
    int getY() { return m_ycoord; }
    int getSpeed() { return m_speed; }
    QPixmap getPicture() { return m_mapObj; }

protected:
    int m_xcoord;
    int m_ycoord;
    int m_speed;
    QPixmap m_mapObj;

private:
    MovingObject() {}


};



#endif // MOVINGOBJECT_H
