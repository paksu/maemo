#include <QtGui>
#include "breakout.h"
#include "paddle.h"

#include <math.h>
#include "ball.h"
#include "tile.h"

 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     Breakout breakout;
     breakout.setSceneRect(0,0, Breakout::get_w(), Breakout::get_h());
     breakout.setItemIndexMethod(QGraphicsScene::NoIndex);
     breakout.addItem(new Ball(100,200));
     //breakout.addItem(new Ball(200,100));
     breakout.generateLevel(0);

     breakout.addItem(new Paddle(&breakout));

     QGraphicsView view(&breakout);
     view.setBackgroundBrush(QPixmap(":/images/bg.png"));
     view.setCacheMode(QGraphicsView::CacheBackground);
     view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     view.setDragMode(QGraphicsView::NoDrag);
     view.setFrameStyle(QGraphicsView::NoFrame);
     view.setResizeAnchor(QGraphicsView::NoAnchor);
     view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "BreakOut"));
     view.resize(Breakout::get_w(), Breakout::get_h());
     // DONT DO IT
     //view.showFullScreen();
     view.show();

     QTimer timer;
     QObject::connect(&timer, SIGNAL(timeout()), &breakout, SLOT(advance()));
     timer.start(100.0/25.0);

     return app.exec();
 }
