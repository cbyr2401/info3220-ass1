#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "game.h"
#include "configuration.h"

#include <QDialog>
#include <QPainter>


class GameEngine : public QDialog
{

    Q_OBJECT
    Game m_game;
    Configuration m_config;
public:
    GameEngine(QWidget *parent = nullptr);
    void play();

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void nextFrame();

};

#endif // GAMEENGINE_H
