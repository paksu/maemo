/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Feb 25 18:37:18 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "gameview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *widgetStack;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startGameButton;
    QPushButton *randomizeButton;
    QHBoxLayout *horizontalLayout;
    QSpinBox *seed;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *mouse;
    QRadioButton *accelerometer;
    QCheckBox *godmode;
    QHBoxLayout *horizontalLayout_2;
    QLabel *gameOverLabel;
    QLabel *scoreLabel;
    GameView *gameView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 480);
        MainWindow->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        widgetStack = new QStackedWidget(centralWidget);
        widgetStack->setObjectName(QString::fromUtf8("widgetStack"));
        widgetStack->setGeometry(QRect(0, 0, 800, 480));
        widgetStack->setLineWidth(0);
        verticalLayoutWidget = new QWidget();
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        startGameButton = new QPushButton(verticalLayoutWidget);
        startGameButton->setObjectName(QString::fromUtf8("startGameButton"));
        startGameButton->setEnabled(true);
        startGameButton->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setPointSize(26);
        startGameButton->setFont(font);
        startGameButton->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        startGameButton->setCheckable(false);

        verticalLayout->addWidget(startGameButton);

        randomizeButton = new QPushButton(verticalLayoutWidget);
        randomizeButton->setObjectName(QString::fromUtf8("randomizeButton"));
        randomizeButton->setMinimumSize(QSize(600, 100));
        randomizeButton->setFont(font);

        verticalLayout->addWidget(randomizeButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        seed = new QSpinBox(verticalLayoutWidget);
        seed->setObjectName(QString::fromUtf8("seed"));
        QFont font1;
        font1.setPointSize(28);
        seed->setFont(font1);

        horizontalLayout->addWidget(seed);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mouse = new QRadioButton(verticalLayoutWidget);
        mouse->setObjectName(QString::fromUtf8("mouse"));
        mouse->setFont(font);
        mouse->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"	width: 50px;\n"
"	height: 50px;\n"
"}\n"
""));
        mouse->setChecked(true);

        horizontalLayout_4->addWidget(mouse);

        accelerometer = new QRadioButton(verticalLayoutWidget);
        accelerometer->setObjectName(QString::fromUtf8("accelerometer"));
        accelerometer->setFont(font1);
        accelerometer->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"	width: 50px;\n"
"	height: 50px;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(accelerometer);


        verticalLayout->addLayout(horizontalLayout_4);

        godmode = new QCheckBox(verticalLayoutWidget);
        godmode->setObjectName(QString::fromUtf8("godmode"));
        godmode->setMinimumSize(QSize(0, 0));
        godmode->setBaseSize(QSize(0, 0));
        godmode->setFont(font1);
        godmode->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"	width: 50px;\n"
"	height: 50px;\n"
"}\n"
""));
        godmode->setIconSize(QSize(16, 16));
        godmode->setChecked(false);

        verticalLayout->addWidget(godmode);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gameOverLabel = new QLabel(verticalLayoutWidget);
        gameOverLabel->setObjectName(QString::fromUtf8("gameOverLabel"));
        gameOverLabel->setEnabled(true);
        gameOverLabel->setFont(font);

        horizontalLayout_2->addWidget(gameOverLabel);

        scoreLabel = new QLabel(verticalLayoutWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setEnabled(true);
        scoreLabel->setFont(font);

        horizontalLayout_2->addWidget(scoreLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        widgetStack->addWidget(verticalLayoutWidget);
        gameView = new GameView();
        gameView->setObjectName(QString::fromUtf8("gameView"));
        gameView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gameView->sizePolicy().hasHeightForWidth());
        gameView->setSizePolicy(sizePolicy);
        gameView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::BlankCursor)));
        gameView->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        gameView->setFrameShape(QFrame::NoFrame);
        gameView->setFrameShadow(QFrame::Plain);
        gameView->setLineWidth(0);
        widgetStack->addWidget(gameView);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(startGameButton, SIGNAL(clicked()), gameView, SLOT(startGame()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        startGameButton->setText(QApplication::translate("MainWindow", "start game", 0, QApplication::UnicodeUTF8));
        randomizeButton->setText(QApplication::translate("MainWindow", "Randomize Level", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Level Seed", 0, QApplication::UnicodeUTF8));
        mouse->setText(QApplication::translate("MainWindow", "Touchscreen", 0, QApplication::UnicodeUTF8));
        accelerometer->setText(QApplication::translate("MainWindow", "Accelerometer", 0, QApplication::UnicodeUTF8));
        godmode->setText(QApplication::translate("MainWindow", "Godmode", 0, QApplication::UnicodeUTF8));
        gameOverLabel->setText(QApplication::translate("MainWindow", "Game Over !!!", 0, QApplication::UnicodeUTF8));
        scoreLabel->setText(QApplication::translate("MainWindow", "asd", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
