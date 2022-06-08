#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QInputDialog>
#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <string>
#include <QFile>
#include "game.h"
#include <QTimer>

class mainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *play_button;
    BaseGame *gameWindow;
    QInputDialog *userInput;    
    QLabel  *scoreWindow, *dificuldade3, *dificuldade2, *dificuldade1, *corEscolhida;
    QFile *scoreFile;
    int aux = 0, cor = 1;

public:
    explicit mainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

public slots:
    void miniGame();

    void gameEnd();

signals:

    void mainMenu();

};

#endif // MAINWINDOW_H
