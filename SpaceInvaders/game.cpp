#include "game.h"

#include <QTimer>


void Game::addBullet(int y){
    // TODO:  Add in the settings from config

    QString apath = "images/fireball.png";
    Bullet bulBuilder = Bullet::Builder().setY(y).setImage(apath).build();

    // timer
    //QTimer *timer = new QTimer(q);
    //connect(timer, SIGNAL(timeout()), q, SLOT(bulBuilder.nextFrame()));
    //timer->start(32);

    //Bullet bill = bulBuilder.build();

    m_bullets[m_bullIndex++] = &bulBuilder;

}

void Game::addShip(){
    // TODO:  Add in the settings from config

    QString apath = "images/defender.png";

    SpaceShip shipBuilder = SpaceShip::Builder()
            .setX(0)
            .setY(450)
            .setSpeed(10)
            .setImage(apath)
            .build();

    m_ships[m_shipIndex] = &shipBuilder;
}

void Game::readConfig(std::string path)
{

}

Game::Game(Configuration config)
    :m_config(config)
{}


void Game::updateBullets() {
    for(int i=0; i < m_bullIndex; i++) {
        m_bullets[i]->advance();
    }
}


void Game::step(std::string instruction){


    // change this is allowing for more than one spaceship
    SpaceShip* ship = m_ships[0];


    if(instruction == "RIGHT"){
        ship->moveRight();
    }else if(instruction == "LEFT"){
        ship->moveLeft();
    }else if(instruction == "SHOT"){
        addBullet(ship->getY());
    }

}


void Game::update(QPainter *painter){
    // update / redraw the spaceship
    m_ships[0]->draw(painter);

    // update / redraw the bullets
    for(int i=0; i < m_bullIndex; i++) {
        m_bullets[i]->draw(painter);
    }

    // any more steps?
}
