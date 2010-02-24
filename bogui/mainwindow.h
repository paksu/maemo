#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
    void on_gameView_noticeGameOver(int);
    void on_gameView_gameStopped();
    void on_startGameButton_clicked();
    void on_randomizeButton_clicked();
};

#endif // MAINWINDOW_H
