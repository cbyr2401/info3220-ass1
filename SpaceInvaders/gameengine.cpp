#include "gameengine.h"

GameEngine::GameEngine(QWidget *parent) : QDialog(parent)
{
    // load items
    Configuration config = Configuration("config.txt");
    std::cout << "Parsing File Successful" << std::endl;
    Game game = Game(config);
    std::cout << "Creating Game Successful" << std::endl;

    game.addShip(config);
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

    QTimer *t2 = new QTimer(this);
    connect(t2, SIGNAL(timeout()), this, SLOT(nextCMD()));
    t2->start(500);

    std::cout << "Timer Successful" << std::endl;
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
