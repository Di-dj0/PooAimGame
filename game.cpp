#include "mainwindow.h"
#include "game.h"

Game::Game(int qnt){
    this->qnt = qnt;
}

Game::Game(double timeLimit){
    this->timeLimit = timeLimit;
}

double Game::score = 0;

void Game::createButton(){
    int rand1, rand2;
    rand1 = rand()%(600-350 + 1) + 350;
    rand2 = rand()%(600-100 + 1) + 100;

    for(int i = 0; i < qnt; i++){
        Button *b = new Button(rand1, rand2);
        rand1 = rand()%(600-350 + 1) + 350;
        rand2 = rand()%(600-100 + 1) + 100;
        buttons.push_back(b);
    }

    it = buttons.begin();

}

void Game::showButton(){
    time->start();
    (*it)->show();
    connect((*it), SIGNAL(clicked(bool)), this, SLOT(nextButton()));
}

void Game::nextButton(){
    (*it)->hide();
    it++;

    if(it == buttons.end()){
        time->stop();
        score = double(time->interval()/1000);
        emit gameEnd();
    }
    else{
        showButton();
    }
}
