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

    virtual int getX() { return m_xcoord; }
    virtual int getY() { return m_ycoord; }
    virtual int getSpeed() { return m_speed; }
    virtual QPixmap getPicture() { return m_mapObj; }

protected:
    int m_xcoord;
    int m_ycoord;
    int m_speed;
    QPixmap m_mapObj;

private:
    MovingObject() {}


};



#endif // MOVINGOBJECT_H
