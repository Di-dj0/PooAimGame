#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    this->setGeometry(100,100,800,600);

    minigame1 = new QPushButton("Minigame 1", this);
    minigame1->setGeometry(690,20,90,40);

    minigame2 = new QPushButton("Minigame 2", this);
    minigame2->setGeometry(690,80,90,40);

    connect(minigame1, SIGNAL(clicked(bool)), this, SLOT(pequenoJogo1()));

    connect(minigame2, SIGNAL(clicked(bool)), this, SLOT(pequenoJogo2()));
}

void mainWindow::pequenoJogo1(){

}

void mainWindow::pequenoJogo2(){

}
