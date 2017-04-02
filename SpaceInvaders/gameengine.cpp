#include "gameengine.h"

GameEngine::GameEngine(QWidget *parent) : QDialog(parent)
{
    // load items
    Configuration config = Configuration("config.txt");
    std::cout << "Parsing File Successful" << std::endl;
    Game game = Game(config);
    std::cout << "Creating Game Successful" << std::endl;

    game.addShip();
    std::cout << "Added Ship Successful" << std::endl;

    // set background
    setStyleSheet("background-color: #000000");
    std::cout << "Set Stylesheet Successful" << std::endl;

    // set window size
    this->resize(600, 400);
    std::cout << "Resize Successful" << std::endl;

    // set up the timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    std::cout << "Timer Successful" << std::endl;
    m_game = game;

}

void GameEngine::play(){

}

void GameEngine::paintEvent(QPaintEvent *event) {
    // declare a new QPainter
    QPainter painter(this);

    // pass to game:
    m_game.update(&painter);

}
void GameEngine::nextFrame() {
    // animate the defender
    int maxX = this->width()-m_game.getSpaceShip()->getPicture().width();
    //dx += ds;
/*
    if( m_game.getSpaceShip()->getX() >= maxX){
        m_game.getSpaceShip()->moveLeft();
    } else if (m_game.getSpaceShip()->getX() <= 0) {
        m_game.getSpaceShip()->moveRight();
    }
    */
    // shoot or animate the bullet
    /*if(by <= -100){
        bx = dx + (defender.width()/2) - (bullet.width()/2);
        by = dy - bullet.height();
    } else {
        by -= bs;
    }*/
    update();



    /*// bullet check
    m_game.updateBullets();

    // process next move
    m_game.step(m_config.nextCommand()); */

    // update
    //update();

}
