#include "mainwindow.h"
#include "game.h"

Game::Game(int qnt, int difficult){
    this->qnt = qnt;
    this->difficult = difficult;
}

Game::Game(double timeLimit){
    this->timeLimit = timeLimit;
}

double Game::score = 0;

void Game::createButton(){

    //settings de dificuldade baseado no tamanho do quadrado
    //easy = 100, medium = 75, hard = 50.

    switch(difficult){
        case 3:
            tam = 50;
        break;
        case 2:
            tam = 75;
        break;
        default:
            tam = 100;
        break;
    }

    int rand1, rand2;
    rand1 = rand()%(480-10 + 1) + 10;
    rand2 = rand()%(480-10 + 1) + 10;

    for(int i = 0; i < qnt; i++){
        QPushButton *b = new QPushButton(this);
        b->setGeometry(rand1, rand2, tam, tam);
        rand1 = rand()%(480-10 + 1) + 10;
        rand2 = rand()%(480-10 + 1) + 10;
        buttons.push_back(b);
    }

    it = buttons.begin();

}

void Game::showButton(){
    if(time->isActive() != true){
        time->setInterval(500000);
        time->start();
    }

    (*it)->show();
    connect((*it), SIGNAL(clicked(bool)), this, SLOT(nextButton()));
}

void Game::nextButton(){
    (*it)->hide();
    it++;

    if(it == buttons.end()){
        time->stop();
        score = double((500000 - time->remainingTime())/1000);
        emit gameEnd();
    }
    else{
        showButton();
    }
}
