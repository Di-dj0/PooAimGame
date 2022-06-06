#ifndef BUTTON2_H
#define BUTTON2_H

#include <QWidget>

class button2 : public QWidget
{
    int pos_x,pos_y;
    Q_OBJECT
    QMouseEvent* button;

public:
    explicit button2(QWidget *parent = nullptr);
    explicit button2(int posx, int posy);

    void paintEvent(QPaintEvent *event);

    void showButton();


signals:

};

#endif // BUTTON2_H
