#include <QDebug>

#include "paddle.h"
#define HEIGHT 10

Paddle::Paddle(Breakout* b)
    : speed(1.0), width(Paddle::NORMAL), bonusWidth(0), timer(0)
{

    setRect(QRectF(-width/2, -HEIGHT/2, width, HEIGHT));
    setPos(QPointF(400, 400));
    parent = b;
}

void Paddle::advance(int phase)
{
    if(!phase) {
        if(!scene()->collidingItems(this).isEmpty()) {
            handleCollision();
        }
        setPos(QPointF(Breakout::mousePos, 400.0));
        //setPos(QPointF(Breakout::read_acc() + 400.0, 400.0));
        return;
    }
    //setPos(QPointF(400, 400));
}

void Paddle::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(timer && bonusWidth) {
        painter->drawPixmap(-bonusWidth/2, -HEIGHT/2, QPixmap(":images/big_paddle.png"));
        //hitbox
        painter->drawRect(rect());
        timer--;
        if(!timer) {
            setRect(QRectF(-width/2, -HEIGHT/2, width, HEIGHT));
        }
    } else {
        painter->drawPixmap(-width/2, -HEIGHT/2, QPixmap(":images/paddle.png"));
        //hitbox
        painter->drawRect(rect());
    }
}

QRectF Paddle::boundingRect() const
{
    return rect();
}

Vector2D Paddle::collision(Ball const* ball)
{
    qDebug() << "paddle collision";
    Vector2D impulse = CollidingItem::collision(ball);
    //impulse.x += (x1 - x2) / 5.0;
    return impulse;
}
void Paddle::handleCollision() {
    QList <QGraphicsItem *> collision_list = scene()->collidingItems(this);

    for (QList<QGraphicsItem *>::ConstIterator it = collision_list.constBegin();
        it != collision_list.constEnd(); it++) {
        if (typeid(**it) == typeid(Bonus)) {
            Bonus * b = static_cast<Bonus *>(*it);
            switch(b->bonusType)
            {
                case Bonus::PADDLE:
                    bonusWidth = LARGE;
                    setRect(QRectF(-bonusWidth/2, -HEIGHT/2, bonusWidth, HEIGHT));
                    timer = 500;
                break;

                case Bonus::SCORE:
                    parent->addScore(10000);
                break;

                case Bonus::BALL:
                    parent->addItem(new Ball(x(),y()-20));
                break;
            }
            delete (*it);
        }
    }
}
