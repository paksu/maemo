#include <QtGui>
#include "breakout.h"
#include "paddle.h"



#include <math.h>
#include "ball.h"


 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

     Breakout breakout;
     breakout.setSceneRect(0,0, 800, 480);
     breakout.setItemIndexMethod(QGraphicsScene::NoIndex);

     Ball ball;
     breakout.addItem(&ball);
/*
     for (int i = 0; i < MouseCount; ++i) {
         Mouse *mouse = new Mouse;
         mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                       ::cos((i * 6.28) / MouseCount) * 200);
         breakout.addItem(mouse);
     }
*/
     Paddle* paddle = new Paddle();
     breakout.addItem((QGraphicsRectItem*) paddle);


     QGraphicsView view(&breakout);
     view.setRenderHint(QPainter::Antialiasing);
     view.setBackgroundBrush(QPixmap(":/images/bg.png"));
     view.setCacheMode(QGraphicsView::CacheBackground);
     view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
     view.setDragMode(QGraphicsView::NoDrag);
     view.setFrameStyle(QGraphicsView::NoFrame);
     view.setResizeAnchor(QGraphicsView::NoAnchor);
     view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "BreakOut"));
     view.resize(800, 480);
     view.show();


     QTimer timer;
     QObject::connect(&timer, SIGNAL(timeout()), &breakout, SLOT(advance()));
     timer.start(100 / 25);

     return app.exec();
 }
