#ifndef SPACESHIP_H
#define SPACESHIP_H


#include <QPainter>
#include <QPixmap>
#include <QString>

#include <iostream>


class SpaceShip
{
public:
    class Builder;
    ~SpaceShip();
    void moveLeft();
    void moveRight();
    void draw(QPainter &painter);
    SpaceShip() {}

    int getX() { return m_xcoord; }
    int getY() { return m_ycoord; }
    int getSpeed() { return m_speed; }
    QPixmap getPicture() { return m_mapObj; }

private:

    SpaceShip(int x, int y, int s, QPixmap m);
    QString size;
    void setX(int x);
    int m_xcoord;
    int m_ycoord;
    int m_speed;
    QPixmap m_mapObj;

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
        static const int defaultX = 250;
        static const int defaultY = 250;
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

        //  Run this function to finalise your object.
        //  returns the object.
        SpaceShip build(){
            // hardcoded file names...
            dmap.load("images/defender.png");
            return SpaceShip(this->dx, this->dy, this->ds, this->dmap);
        }
};


#endif // SPACESHIP_H
