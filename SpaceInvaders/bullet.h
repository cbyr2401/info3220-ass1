#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <QPixmap>
#include <QString>

#include <iostream>


class Bullet
{
public:
    class Builder;
    ~Bullet() {}
    void advance();
    void draw(QPainter *painter);

    int getX() { return m_xcoord; }
    int getY() { return m_ycoord; }
    int getSpeed() { return m_speed; }
    QPixmap getPicture() { return m_mapObj; }

protected:


private:
    Bullet(int x, int y, int s, QPixmap m);
    void setY(int y);
    int m_xcoord;
    int m_ycoord;
    int m_speed;
    QPixmap m_mapObj;


public slots:
    virtual void nextFrame();

};

// Bullet Builder Class
class Bullet::Builder {
    private:
        int dx;
        int dy;
        int ds;
        QPixmap dmap;
        QString path;

    public:
        // default values for spaceship if not given any
        static const int defaultX = -1000;
        static const int defaultY = -1000;
        static const int defaultS = 10;
        const QString defaultPath = "/";

        // default Builder
        Builder() : dx(defaultX), dy(defaultY), ds(defaultS) {}

        // custom values for SpaceShip
        // partly taken from examples on the internet
        // returns an address to the builder with new values assigned.
        Builder& setX(const int value) { this->dx = value; return *this; }
        Builder& setY(const int value) { this->dy = value; return *this; }
        Builder& setSpeed(const int value) { this->ds = value; return *this; }
        Builder& setImage(const QString value) { this->path = value; return *this; }

        // returns an address to the builder with new values assigned.
        Builder& set(){
            this->dx = defaultX;
            this->dy = defaultY;
            this->ds = defaultS;
            this->path = defaultPath;
            return *this;
        }

        Bullet build(){
            dmap.load(path);
            return Bullet(this->dx, this->dy, this->ds, this->dmap);
        }
};

#endif // BULLET_H
