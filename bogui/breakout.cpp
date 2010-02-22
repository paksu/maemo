#include "breakout.h"
#include "breakoutlevelgenerator.h"

#include <QDebug>

qreal Breakout::mousePos = 0;

Breakout::Breakout(GameView* theView)
    : theView(theView)
{
    tick_timer = new QTimer();
    tick_timer->setInterval(100 / 25);
    QObject::connect(tick_timer, SIGNAL(timeout()), this, SLOT(advance()));
    scoreText = addSimpleText(QString("0"),QFont("System", 16, QFont::Bold));
    scoreText->setPos(0,450);
    scoreText->setBrush(QBrush(QColor(255,255,255,150)));
    scoreText->setVisible(true);
    scoreText->setZValue(100);
    score = 0;

    back = new ButtonWidget( w() - 25, 25, QPixmap(":images/back.png"));
    back->setZValue(100);
    addItem(back);
    connect(back, SIGNAL(clicked()), theView, SLOT(stopGame()));

    init();
}

Breakout::~Breakout()
{
    delete tick_timer;
}

void Breakout::stop()
{
    tick_timer->stop();
}

void Breakout::start()
{
    qDebug() << "Breakout::start !";
    tick_timer->start();

}

void Breakout::init()
{
    bonusTime = QTime::currentTime();
    // deletePaddles();
    // deleteBalls();
    // deleteTiles();
    addPaddle();
    addBall();
    generateLevel(0);
}

void Breakout::addPaddle()
{
    Paddle* p = new Paddle(this);
    paddles_ += p;
    addItem(p);
}

void Breakout::addBall()
{
    Ball* b = new Ball(100, 200);
    balls_ += b;
    addItem(b);
}
void Breakout::addBonus(Bonus *b)
{
    bonuses_ += b;
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
const QSet<Bonus *> & Breakout::bonuses()
{
    return bonuses_;
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
    // BUGAA ( valgrind )
    scoreText->setText(QString().number(score));
    qDebug() << "Score is " << score;
}

int Breakout::getScore() {
    return score;
}

// mouse
void Breakout::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
   Breakout::mousePos = mouseEvent->scenePos().x();
}

qreal Breakout::w() const
{
    return 800.0;
}

qreal Breakout::h() const
{
    return 480.0;
}
