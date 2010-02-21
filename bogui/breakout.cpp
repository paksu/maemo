#include "breakout.h"

#include <QDebug>

Breakout::Breakout()
{}

void Breakout::start()
{
    //
    // start timer
}

void Breakout::init()
{

    scoreText = addSimpleText(QString("0"),QFont("System", 16, QFont::Bold));
    scoreText->setPos(0,450);
    scoreText->setBrush(QBrush(QColor(255,255,255,150)));
    scoreText->setVisible(true);
    bonusTime = QTime::currentTime();
 }
