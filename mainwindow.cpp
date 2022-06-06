#include "mainwindow.h"
#include "game.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    this->setGeometry(350,100,300,300);

    game1_button = new QPushButton("Minigame 1", this);
    game1_button->setGeometry(50,150,200,50);
    game1_button->style();

    game2_button = new QPushButton("Minigame 2", this);
    game2_button->setGeometry(50,200,200,50);

    connect(game1_button, SIGNAL(clicked(bool)), SLOT(miniGame1()));

    connect(game2_button, SIGNAL(clicked(bool)), SLOT(miniGame2()));


}

double Game::score = 0;

void mainWindow::miniGame1(){

    int qttButtons = QInputDialog::getInt(this,"Espera input", "Digite a quantidade de botoes para ser o limite");

    game1Window = new Game(qttButtons);
    game1Window->setGeometry(350,100,600,600);

    connect(game1Window, SIGNAL(endGame()), this, SLOT(game1End()));

    this->hide();

    game1Window->setTitle("Minigame 1");
    game1Window->show();

}

void mainWindow::miniGame2(){

    this->hide();

    game2Window->show();


}
