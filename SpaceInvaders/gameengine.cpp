#include "gameengine.h"

GameEngine::GameEngine(QWidget *parent) : QDialog(parent)
{
    // load items
    Configuration config = Configuration("config.txt");
    Game game = Game(config);

    game.addShip();

    // set background
    setStyleSheet("background-color: #000000");

    // set window size
    this->resize(600, 400);

    // set up the timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);


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

    // bullet check
    m_game.updateBullets();

    // process next move
    m_game.step(m_config.nextCommand());

    // update
    update();

}
