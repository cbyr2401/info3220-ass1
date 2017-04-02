#include "gameengine.h"

GameEngine::GameEngine(QWidget *parent) : QDialog(parent)
{
    // load items
    Configuration config = Configuration("config.txt");
    Game game = Game(config);

    // create a space ship
    game.addShip(config);

    // set background
    setStyleSheet("background-color: #000000");

    // set window size
    this->resize(600, 400);

    // set up the timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    // set up a slower timer for moving to next command.
    QTimer *t2 = new QTimer(this);
    connect(t2, SIGNAL(timeout()), this, SLOT(nextCMD()));
    t2->start(500);

    // add to the "global" scope / member variables.
    m_game = game;
    m_config = config;

}

void GameEngine::paintEvent(QPaintEvent *event) {
    // declare a new QPainter
    QPainter painter(this);

    // pass to game:
    m_game.update(painter);

}
void GameEngine::nextFrame() {
    // bullet check
    m_game.updateBullets();

    // process next move
    m_game.step(m_config.currentCommand());

    // update
    update();
}

// function for making sure all commands are not consumed instantly
void GameEngine::nextCMD(){
    m_config.nextCommand();
}
