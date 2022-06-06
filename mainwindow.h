#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <QLabel>
#include <string>
#include "game.h"
#include "button.h"
#include <QTimer>

class mainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *game1_button, *game2_button;
    Game *gameWindow, *game2Window;
    QInputDialog *userInput;    
    QLabel  *scoreWindow, *dificuldade3,*dificuldade2,*dificuldade1;
    int aux = 0;

public:
    explicit mainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    int auxCheck();

    void setCheck();

public slots:
    void miniGame1();
    void miniGame2();

    void gameEnd();

signals:

    void mainMenu();

};

#endif // MAINWINDOW_H
