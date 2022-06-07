#include "mainwindow.h"
#include "game.h"
#include <QMessageBox>

Game::Game(int qnt, int difficult, int cor){     //Construtor que atribui a quantidade botões e seus tamanhos
    this->qnt = qnt;
    this->difficult = difficult;
    this->cor = cor;
}


double Game::score = 0;

void Game::createButton(){                              //Aqui começa a criação de botões, gerando de acordo com o tamanho e a quantidade
                                                        //máxima, ambos escolhidos pelo usuário.

    time = new QTimer(this);                            //Cria um timer para saber quanto tempo usuário levou e para calcular posteriormente o score

    switch(difficult){                                  //Atribui o tamanho dos lados do quadrado de acordo com a dificuldade
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

    int rand1, rand2;                                   //Variáveis para armazenar valores aleatorios para surgir os botões
    rand1 = rand()%(480-10 + 1) + 10;
    rand2 = rand()%(480-10 + 1) + 10;

    for(int i = 0; i < qnt; i++){                       //Loop para a criação de um vector de botões
        QPushButton *b = new QPushButton(this);
        b->setGeometry(rand1, rand2, tam, tam);

        if(cor == 0) b->setStyleSheet("background-color: green");
        else if(cor == 1) b->setStyleSheet("background-color: blue") ;
        else b->setStyleSheet("background-color: yellow");

        rand1 = rand()%(480-10 + 1) + 10;
        rand2 = rand()%(480-10 + 1) + 10;
        buttons.push_back(b);
    }

    it = buttons.begin();                               //Atribuição do iterador para o começo do vector
    time->start(500000);
    time->setSingleShot(true);

}

void Game::showButton(){                                //Faz com que o botão apareça e ao ser clicado seja passado para o próximo botão
        (*it)->show();
        connect((*it), SIGNAL(clicked(bool)), this, SLOT(nextButton()));
}

void Game::nextButton(){

    (*it)->hide();                                      //Esconde o botao que foi clicado
    it++;                                               //Vai para o proximo
    /*
        Como o score vai ser baseado no tempo que o jogador demorou para apertar todos os botões, é necessário conseguir o tempo que demorou,
      para isso, usamos o timer da classe QTimer, que é literalmente um timer, um temporizador.

        Logo, para armazenar esse tempo, inicializamos com um tempo de 500 segundos, verificamos quanto tempo ainda tem no timer e
      subtraímos um do outro. Sendo o tempo total de 500 segundos menos o tempo que ainda resta no timer (Por exemplo, se passou 10 segundos,
      o timer guardaria 490 segundos e, fazendo a operação de 500 - 490, saberíamos que passou 10 segundos.

        Para isso, foi necessário criar e tratar um exceção para que caso o usuário demore mais de 500 segundos, ele seja avisado que demorou
      muito e não de erro.
    */
    try{
        if(time->remainingTime() > 0){
            if(it == buttons.end()){
                double score_max = static_cast<double>(qnt * difficult * 5.0);
                double time_passed = static_cast<double>((500000.0 - static_cast<double>(time->remainingTime()))/1000.0);
                score = static_cast<double>(score_max - time_passed);
                time->stop();
                emit gameEnd();
            }
            else{
                showButton();
            }
        }
        else
            throw -1;
    }
    catch(...) {
        QMessageBox::critical(this, "erro",  "Voce demorou muito!");
        emit gameEnd();
    }
}

