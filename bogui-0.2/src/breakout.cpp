#include "breakout.h"
#include "breakoutlevelgenerator.h"

#include <QDebug>

qreal Breakout::paddlePos = 0;

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
    controlMethod = true;
    godmode = false;

    back = new ButtonWidget( w() - 25, 25, QPixmap(":images/back.png"));
    back->setZValue(100);
    addItem(back);
    connect(back, SIGNAL(clicked()), theView, SLOT(stopGame()));
    connect(this, SIGNAL(endGame(int)), theView, SLOT(gameEnded(int)));
}

Breakout::~Breakout()
{
    delete tick_timer;
    delete back;
    delete scoreText;
    deletePaddles();
    deleteBalls();
    deleteTiles();
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

void Breakout::gameOver()
{
    emit endGame(score);
}


void Breakout::init()
{
    bonusTime = QTime::currentTime();
    deletePaddles();
    deleteBalls();
    deleteTiles();
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
QSet<Tile*> & Breakout::tiles()
{
    return tiles_;
}

QSet<Paddle*> & Breakout::paddles()
{
    return paddles_;
}
QSet<Bonus *> & Breakout::bonuses()
{
    return bonuses_;
}
QSet<Ball *> & Breakout::balls()
{
    return balls_;
}

void Breakout::generateLevel(const int & seed) {
    int rows = 10;
    BreakoutLevelGenerator generator(seed);
    generator.generate_level(this);
}

void Breakout::deletePaddles()
{
    QList<Paddle*> list = paddles_.values();
    QList<Paddle*>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        removeItem(*it);
        delete *it;
    }
    paddles_.clear();
}

void Breakout::deleteBalls()
{
    QList<Ball*> list = balls_.values();
    QList<Ball*>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        removeItem(*it);
        delete *it;
    }
    balls_.clear();
}
void Breakout::deleteTiles()
{
    QList<Tile*> list = tiles_.values();
    QList<Tile*>::iterator it;
    for (it = list.begin(); it != list.end(); it++) {
        removeItem(*it);
        delete *it;
    }
    tiles_.clear();
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

// mouse
void Breakout::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(controlMethod) { //  mousecontrol
        Breakout::paddlePos = mouseEvent->scenePos().x();
    }
}

qreal Breakout::w() const
{
    return 800.0;
}

qreal Breakout::h() const
{
    return 480.0;
}
void Breakout::setGodmode(bool godmode_) {
    godmode = godmode_;
}
bool Breakout::getGodmode() {
    return godmode;
}
void Breakout::setControlMethod(bool controlMethod_) {
    controlMethod = controlMethod_;
}
bool Breakout::getControlMethod() {
    return controlMethod;
}
