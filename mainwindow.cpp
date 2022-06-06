#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    this->setGeometry(350,100,300,300);

    minigame1 = new QPushButton("Minigame 1", this);
    minigame1->setGeometry(50,150,200,50);

    minigame2 = new QPushButton("Minigame 2", this);
    minigame2->setGeometry(50,200,200,50);

    game1 = new QWindow();
    game1->setGeometry(350,100,600,600);


    connect(minigame1, SIGNAL(clicked(bool)), this, SLOT(pequenoJogo1()));

    connect(minigame2, SIGNAL(clicked(bool)), this, SLOT(pequenoJogo2()));

}

void mainWindow::pequenoJogo1(){
    double time = QInputDialog::getDouble(this,"Espera input", "Digite o tempo para o jogo começar");
    int dificult = QInputDialog::getInt(this,"Escolha a dificuldade", "Digite um valor entre 1 e 3 para a dificuldade",
                                        0, 1, 3);


    this->hide();

    game1->show();



}

void mainWindow::pequenoJogo2(){

}
