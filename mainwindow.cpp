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

    scoreWindow = new QLabel(this);

    QString aux = "Score: ";
    aux.append(QString::number(Game::score, 'g', 2));
    scoreWindow->setText(aux);
    scoreWindow->setGeometry(50,100,200,50);

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

    int qttButtons = QInputDialog::getInt(this,"Espera input", "Digite a quantidade de botoes para ser o limite", 0, 1);
    int difficult = QInputDialog::getInt(this,"Espera input", "Digite a dificuldade", 0, 1, 3);

    gameWindow = new Game(qttButtons, difficult);
    gameWindow->setGeometry(350,100,600,600);

    connect(gameWindow, SIGNAL(gameEnd()), this, SLOT(gameEnd()));

    this->hide();

    gameWindow->setWindowTitle(QString::fromStdString("Minigame 1"));
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

    gameWindow->setWindowTitle(QString::fromStdString("Minigame 2"));
    gameWindow->show();

}

void mainWindow::gameEnd(){
    gameWindow->hide();
    delete gameWindow;
    this->show();
    QString aux = "Score: ";
    aux.append(QString::number(Game::score, 'g', 2));
    scoreWindow->setText(aux);

}
