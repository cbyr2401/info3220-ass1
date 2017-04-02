#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "game.h"
#include "configuration.h"

#include <QDialog>
#include <QPainter>


class GameEngine : public QDialog
{
public:
    Q_OBJECT
    GameEngine(QWidget *parent = nullptr);
    void play();

private:
    Game m_game;
    Configuration m_config;

protected:
    void paintEvent(QPaintEvent *event);


public slots:
    void nextFrame();

};

#endif // GAMEENGINE_H
