#include "breakout.h"
#include "breakoutlevelgenerator.h"

#include <QDebug>

Breakout::Breakout()
{
    tick_timer = new QTimer();
    tick_timer->setInterval(100 / 25);
    QObject::connect(tick_timer, SIGNAL(timeout()), this, SLOT(advance()));

    setSceneRect (0 , 0, width(), height() );
}

Breakout::~Breakout()
{
    delete tick_timer;
}

void Breakout::start()
{
    qDebug() << "Breakout::start !";
    addPaddle();
    addBall();
    generateLevel(0);
    tick_timer->start();
}

void Breakout::init()
{
    scoreText = addSimpleText(QString("0"),QFont("System", 16, QFont::Bold));
    scoreText->setPos(0,450);
    scoreText->setBrush(QBrush(QColor(255,255,255,150)));
    scoreText->setVisible(true);
    bonusTime = QTime::currentTime();
}

void Breakout::addPaddle()
{
    Paddle* p = new Paddle();
    paddles_ += p;
    addItem(p);
}

void Breakout::addBall()
{
    Ball* b = new Ball(100, 100);
    balls_ += b;
    addItem(b);
}

const QSet<Tile*> & Breakout::tiles()
{
    return tiles_;
}

const QSet<Paddle*> & Breakout::paddles()
{
    return paddles_;
}


void Breakout::generateLevel(const int & seed) {
    int rows = 10;
    BreakoutLevelGenerator generator(seed);
    //generator.generate_level(this);

    for (int i = rows;i > 0;i--) {
        for (int j = 1;j < (width()/60);j++) {
            Tile* t = new Tile(j,i,6-i/2, this);
            tiles_ += t;
            this->addItem(t);
       }
    }
}

void Breakout::addScore(int newScore) {
    qDebug() << 100 /  1 + bonusTime.secsTo(QTime::currentTime());
    score += newScore;
    score += newScore * (10 / 1 + bonusTime.secsTo(QTime::currentTime()));
    scoreText->setText(QString().number(score));
    qDebug() << "Score is " << score;
}

int Breakout::getScore() {
    return score;
}
