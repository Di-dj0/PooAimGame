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

void mainWindow::miniGame1(){

    double time = QInputDialog::getDouble(this,"Espera input", "Digite o tempo para o jogo começar");
    int difficult = QInputDialog::getInt(this,"Escolha a dificuldade", "Digite um valor entre 1 e 3 para a dificuldade", 0, 1, 3);
    int shape = QInputDialog::getInt(this,"Escolha a forma", "Digite um valor entre 1 e 3 para a forma", 0, 1, 3);

    game1Window = new game(/*shape,*/ difficult, time);
    game1Window->setGeometry(350,100,600,600);

    this->hide();

    game1Window->setTitle("Minigame 1");
    game1Window->show();



}

void mainWindow::miniGame2(){

    int qttButtons = QInputDialog::getInt(this,"Espera input", "Digite a quantidade de botoes para ser o limite");

    this->hide();
    game2Window->show();

}
