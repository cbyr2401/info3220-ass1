#include "game.h"




void Game::addBullet(){
    // TODO:  Add in the settings from config



    // ISSUE
    //
    //  The builder class does not have a type and appears
    //   to be calling the empty contructor for each.


    QString apath = "/";
    Bullet bulBuilder = Bullet::Builder().setX(0).setImage(apath).build();

    //Bullet bill = bulBuilder.build();

    m_bullets[m_bullIndex++] = &bulBuilder;

}

void Game::addShip(){
    // TODO:  Add in the settings from config

    QString apath = "/";

    SpaceShip shipBuilder = SpaceShip::Builder()
            .setX(0)
            .setY(450)
            .setSpeed(10)
            .setImage(apath)
            .build();

    m_ships[m_shipIndex] = &shipBuilder;
}

