#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
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
    QMessageBox  *scoreWindow;
    int aux = 0;

public:
    explicit mainWindow(QWidget *parent = nullptr);

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
