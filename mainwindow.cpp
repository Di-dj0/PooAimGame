#include "mainwindow.h"
#include "game.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    this->setGeometry(650,200,600,400);                         //Define o tamanho da janela
    this->setStyleSheet("background-color : gray");             //Escolhe a cor de fundo

    play_button = new QPushButton("Jogar", this);               //Cria o botao de play
    play_button->setGeometry(50,175,200,50);

    scoreWindow = new QLabel(this);                             //Cria os labels para aparecer no menu
    dificuldade3 = new QLabel(this);
    dificuldade2 = new QLabel(this);
    dificuldade1 = new QLabel(this);
    corEscolhida = new QLabel(this);

    QString aux_str = "Score: ";
    aux_str.append(QString::number(Game::score, 'g', 4));
    scoreWindow->setText(aux_str);
    scoreWindow->setGeometry(50,100,200,50);

    aux_str = "Dificuldade 3: ";
    dificuldade3->setText(aux_str);
    dificuldade3->setGeometry(325, 45, 100, 50);

    aux_str = "Dificuldade 2: ";
    dificuldade2->setText(aux_str);
    dificuldade2->setGeometry(325, 130, 100, 50);

    aux_str = "Dificuldade 1: ";
    dificuldade1->setText(aux_str);
    dificuldade1->setGeometry(325, 240, 100, 50);

    aux_str = "Cor escolhida: ";
    aux_str.append(QString::number(cor, 10));
    corEscolhida->setText(aux_str);
    corEscolhida->setGeometry(50, 50, 100, 50);

    connect(play_button, SIGNAL(clicked(bool)), SLOT(miniGame()));   //Faz o botão de jogar inicializar o minigame


}

void mainWindow::miniGame(){

    int qttButtons = QInputDialog::getInt(this,"Espera input", "Digite a quantidade de botoes para ser o limite", 0, 1);//Atribui a qntd maxima de botoes a qttButtons
    int difficult = QInputDialog::getInt(this,"Espera input", "Digite a dificuldade", 0, 1, 3);//Atribui a dificuldade a difficult

    gameWindow = new Game(qttButtons, difficult, cor);
    gameWindow->setGeometry(350,100,600,600);                                                  //Seta o tamanho da janela
    gameWindow->setStyleSheet("background-color: black");                                      //Escolhe a cor de fundo

    connect(gameWindow, SIGNAL(gameEnd()), this, SLOT(gameEnd()));                             //Relaciona a janela do game, essa janela e o método de gameEnd

    this->hide();

    gameWindow->setWindowTitle(QString::fromStdString("Minigame"));                            //Da o nome da janela de "Minigame"
    gameWindow->show();                                                                        //Mostra a janela

    gameWindow->createButton();                                                                //Cria o vector de botoes
    gameWindow->showButton();                                                                  //Chama o metodo showButton que inicializa o game
}

void mainWindow::gameEnd(){                                                                    //Metodo para finalizar o game
    gameWindow->hide();                                                                        //Esconde a janela de game
    delete gameWindow;                                                                         //Apaga ela
    this->show();                                                                              //Mostra a janela principal
    QString aux = "Score: ";
    aux.append(QString::number(Game::score, 'g', 4));
    scoreWindow->setText(aux);                                                                 //Coloca o score na tela
}

void mainWindow::paintEvent(QPaintEvent *event) {                                              //Desenha na tela os quadrados que representam as dificuldades
     Q_UNUSED(event);

     QPainter painter(this);

     QBrush brusher(Qt::green);
     painter.setBrush(brusher);
     painter.drawRect(475,50,50,50);

     brusher.setColor(Qt::blue);
     painter.setBrush(brusher);
     painter.drawRect(462.5,125,75,75);

     brusher.setColor(Qt::yellow);
     painter.setBrush(brusher);
     painter.drawRect(450,225,100,100);

     if(cor == 0) {
         brusher.setColor(Qt::green);
         painter.setBrush(brusher);
         painter.drawRect(150,65,25,25);
     }
     else if(cor == 1) {
         brusher.setColor(Qt::blue);
         painter.setBrush(brusher);
         painter.drawRect(150,65,25,25);
     }
     else {
         brusher.setColor(Qt::yellow);
         painter.setBrush(brusher);
         painter.drawRect(150,65,25,25);
     }
     this->update();

}

void mainWindow::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        if(cor < 2) cor++;
    }
    else{
        if(cor > 0) cor--;
    }

}




