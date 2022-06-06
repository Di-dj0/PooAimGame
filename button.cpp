#include "mainwindow.h"
#include "game.h"
#include "button.h"

Button::Button(int posx, int posy){
        this->pos_x = posx;
        this->pos_y = posy;
        setGeometry(posx, posy, 50, 100);
        //button = new QMouseEvent();//Ele vai registrar o evento do mouse que ocorrer nas coordenadas que foram pintadas
}

void Button::showButton(){

}

void Button::paintEvent(QPaintEvent *event){
    QPainter painter(this);//Parametro eh onde vai ser desenhado, como passar a window do game?
    QBrush brusher(Qt::green);
    painter.setBrush(brusher);
    painter.drawEllipse(pos_x,pos_y, 500, 1000);

}
