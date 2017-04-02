#include "game.h"

#include <QTimer>
#include <unistd.h>


void Game::addBullet(int x){
    // TODO:  Add in the settings from config

    QString apath = "images/fireball.png";
    m_bullet = Bullet::Builder()
            .setY(350)
            .setX(x)
            .setSpeed(10)
            .setImage(apath)
            .build();

    m_bullIndex++;

    //m_bullets[m_bullIndex++] = &bulBuilder;

}

void Game::addShip(Configuration config){
    // TODO:  Add in the settings from config

    QString apath = "images/defender.png";

    m_ship = SpaceShip::Builder()
            .setX(config.startPosition())
            .setY(350)
            .setSpeed(3)
            .setImage(apath)
            .build();
}

void Game::readConfig(std::string path)
{

}

Game::Game(Configuration config)
    :m_config(config)
{}


void Game::updateBullets() {
    //for(int i=0; i < m_bullIndex; i++) {
        m_bullet.advance();
    //}
}


void Game::step(std::string instruction){


    // change this is allowing for more than one spaceship
    //SpaceShip* ship = m_ships[0];

    std::cout << instruction << std::endl;

    if(instruction == "RIGHT"){
        m_ship.moveRight();
    }else if(instruction == "LEFT"){
        m_ship.moveLeft();
    }else if(instruction == "SHOT"){
        int position = m_ship.getX() + (m_ship.getPicture().width()/2);
        addBullet(position);
        m_config.nextCommand();
    }else{
        std::cout << "No Command Found" << std::endl;
    }
}


void Game::update(QPainter &painter){
    // update / redraw the spaceship
    //m_ships[0]->draw(painter);
    m_ship.draw(painter);

    // WORKING
    //painter.drawPixmap(m_ship.getX()
    //                   ,m_ship.getY()
    //                  , m_ship.getPicture());
    // WORKING END

    // update / redraw the bullets
    //for(int i=0; i < m_bullIndex; i++) {
    //    m_bullets[i]->draw(painter);
    //}
    if(m_bullIndex) { m_bullet.draw(painter); }

    // any more steps?
}
