#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include "configuration.h"
#include "game.h"

#include <QDialog>
#include <QPainter>


class GameEngine : public QDialog
{
    Q_OBJECT
    Game m_game;
    Configuration m_config;
public:
    GameEngine(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void nextFrame();
    void nextCMD();

};

#endif // GAMEENGINE_H
