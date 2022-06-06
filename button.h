#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>

class Button : public QPushButton
{
    int pos_x,pos_y;
    Q_OBJECT
    QMouseEvent* button;

public:

    Button(int posx, int posy);

    void paintEvent(QPaintEvent *event);

    void showButton();

};

#endif // BUTTON_H
