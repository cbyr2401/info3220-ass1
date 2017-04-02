#include "game.h"

#include <QTimer>
#include <unistd.h>


void Game::addBullet(int x){
    // TODO:  Add in the settings from config

    // get the image to display
    QString apath = "images/fireball.png";

    // setup the new bullet using the builder.
    m_bullet = Bullet::Builder()
            .setY(350)
            .setX(x)
            .setSpeed(10)
            .setImage(apath)
            .build();

    // increment the number of bullets on the display
    m_bullIndex++;

    // TODO:  update to allow for multiple bullets at
    //         the same time.
    //m_bullets[m_bullIndex++] = &bulBuilder;

}

void Game::addShip(Configuration config){
    // TODO:  Add in the settings from config

    // get the image to display
    QString apath = "images/defender.png";

    // setup the new spaceship using the builder.
    m_ship = SpaceShip::Builder()
            .setX(config.startPosition())
            .setY(350)
            .setSpeed(3)
            .setImage(apath)
            .build();
}

// basic constructor
Game::Game(Configuration config)
    :m_config(config)
{}

// function to update the position of all the bullets on the display
void Game::updateBullets() {
    //for(int i=0; i < m_bullIndex; i++) {
        m_bullet.advance();
    //}
}


void Game::step(std::string instruction){

    // decide what the instruction is...
    if(instruction == "RIGHT"){
        // move the spaceship right
        m_ship.moveRight();
    }
    else if(instruction == "LEFT"){
        // move the spaceship left
        m_ship.moveLeft();
    }
    else if(instruction == "SHOT"){
        // fire a bullet, work out position first...
        int position = m_ship.getX() + (m_ship.getPicture().width()/2);

        // create the new bullet.
        addBullet(position);

        // move to the next command (because we don't want to be
        //  constantly making bullets).
        m_config.nextCommand();
    }
    else{
        // output an error if no command is reconised.
        std::cout << "No Command Found" << std::endl;
    }
}

// function to update the state of the game after a certain
//  amount of time has passed (as determined by GameEngine)
void Game::update(QPainter &painter){
    // update / redraw the spaceship
    m_ship.draw(painter);

    // update / redraw the bullets
    //for(int i=0; i < m_bullIndex; i++) {
    //    m_bullets[i]->draw(painter);
    //}
    if(m_bullIndex) { m_bullet.draw(painter); }

    // any extra pos-processing steps can go here.
}
