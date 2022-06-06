#include "mainwindow.h"
#include "game.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    this->setGeometry(350,100,300,300);

    game1_button = new QPushButton("Minigame 1", this);
    game1_button->setGeometry(50,150,200,50);

    game2_button = new QPushButton("Minigame 2", this);
    game2_button->setGeometry(50,200,200,50);

    scoreWindow = new QMessageBox();
    scoreWindow->setWindowTitle("Pontuação");

    connect(game1_button, SIGNAL(clicked(bool)), SLOT(miniGame1()));

    connect(game2_button, SIGNAL(clicked(bool)), SLOT(miniGame2()));

}

void mainWindow::setCheck(){
    aux = 0;
}

int mainWindow::auxCheck(){
    return aux;
}

void mainWindow::miniGame1(){

    int qttButtons = QInputDialog::getInt(this,"Espera input", "Digite a quantidade de botoes para ser o limite");

    gameWindow = new Game(qttButtons);
    gameWindow->setGeometry(350,100,600,600);

    connect(gameWindow, SIGNAL(gameEnd()), this, SLOT(gameEnd()));

    this->hide();

    gameWindow->setTitle("Minigame 1");
    gameWindow->show();

    gameWindow->createButton();
    gameWindow->showButton();

}

void mainWindow::miniGame2(){

    double timeLimit = QInputDialog::getInt(this,"Espera input", "Digite a quantidade de segundos para ser o limite");

    gameWindow = new Game(timeLimit);
    gameWindow->setGeometry(350,100,600,600);

    connect(gameWindow, SIGNAL(gameEnd()), this, SLOT(gameEnd()));

    this->hide();

    gameWindow->setTitle("Minigame 2");
    gameWindow->show();

}

void mainWindow::gameEnd(){
    gameWindow->hide();
    delete gameWindow;
    std::string aux = "Score: ";
    aux += std::to_string(Game::score);
    //scoreWindow->setInformativeText(QString(aux));
    this->show();

}
