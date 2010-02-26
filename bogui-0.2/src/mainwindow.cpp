#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameOverLabel->hide();
    ui->scoreLabel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_randomizeButton_clicked()
{
   ui->seed->setValue(rand()%15);
}

void MainWindow::on_startGameButton_clicked()
{
    ui->widgetStack->setCurrentWidget(ui->gameView);
    ui->gameView->startGame(ui->seed->value());
    ui->gameView->setGodmode(ui->godmode->isChecked());
    ui->gameView->setControlMethod(ui->mouse->isChecked());
    showFullScreen();
}

#include <QDebug>
void MainWindow::on_gameView_gameStopped()
{
    qDebug() << "on_gameView_gameStopped";
    ui->widgetStack->setCurrentWidget(ui->verticalLayoutWidget);
    showMaximized();
}

void MainWindow::on_gameView_noticeGameOver(int score)
{
    ui->gameOverLabel->show();
    ui->scoreLabel->setText("score: " + QString().number(score));
    ui->scoreLabel->show();
    on_gameView_gameStopped();
}
