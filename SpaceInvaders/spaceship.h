#ifndef SPACESHIP_H
#define SPACESHIP_H


#include "movingobject.h"


class SpaceShip : protected MovingObject
{
public:
    class Builder;
    ~SpaceShip() {}
    void moveLeft();
    void moveRight();
    //void shoot();
    //void draw();


protected:


private:
    SpaceShip(int x, int y, int s, QPixmap m)
        : MovingObject(x,y,s,m) {}
        //: m_xcoord(x), m_ycoord(y), m_speed(s), m_mapObj(m){}
    QString size;
    void setX(int x);


public slots:
    virtual void nextFrame();

};



// Spaceship Builder Class
class SpaceShip::Builder {
    private:
        int dx;
        int dy;
        int ds;
        QPixmap dmap;
        QString dsize;
        QString path;

    public:
        // default values for spaceship if not given any
        static const int defaultX = 0;
        static const int defaultY = 350;
        static const int defaultS = 3;

        // default Builder
        Builder() : dx(defaultX), dy(defaultY), ds(defaultS) {}

        // custom values for SpaceShip
        // partly taken from examples on the internet
        // returns an address to the builder with new values assigned.
        Builder& setX(const int value) { this->dx = value; return *this; }
        Builder& setY(const int value) { this->dy = value; return *this; }
        Builder& setSpeed(const int value) { this->ds = value; return *this; }
        Builder& setImage(const QString value) { this->path = value; return *this; }
        Builder& setSize(const QString value) { this->dsize = value; return *this; }

        // returns an address to the builder with new values assigned.
        Builder& set(){
            this->dx = defaultX;
            this->dy = defaultY;
            this->ds = defaultS;
            return *this;
        }

        SpaceShip build(){
            dmap.load(path);
            return SpaceShip(this->dx, this->dy, this->ds, this->dmap);
        }
};


#endif // SPACESHIP_H
