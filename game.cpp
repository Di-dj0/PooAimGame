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
    time = new QTimer(this);
    //time->setInterval(500000);

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
        b->setStyleSheet("background-color: orange");
        rand1 = rand()%(480-10 + 1) + 10;
        rand2 = rand()%(480-10 + 1) + 10;
        buttons.push_back(b);
    }

    it = buttons.begin();
    time->start(500000);

}

void Game::showButton(){
//    try{

     (*it)->show();
//        if(time->remainingTime() > 0)
      connect((*it), SIGNAL(clicked(bool)), this, SLOT(nextButton()));
//        else
//            throw -1;
//    }
//    catch(...) {
//        QErrorMessage *error_time = new QErrorMessage(this);
//        error_time->showMessage(QString::fromStdString("Voce demorou muito!"));
//        emit gameEnd();
//    }
//    (*it)->show();
//    connect((*it), SIGNAL(clicked(bool)), this, SLOT(nextButton()));

}

void Game::nextButton(){

    (*it)->hide();
    it++;

    if(it == buttons.end()){
        double score_max = static_cast<double>(qnt * difficult * 5.0);
        double time_passed = static_cast<double>((500000.0 - static_cast<double>(time->remainingTime()))/1000.0);
        score = static_cast<double>(score_max - (time_passed * difficult));
        time->stop();
        emit gameEnd();
    }
    else{
        showButton();
    }

}

