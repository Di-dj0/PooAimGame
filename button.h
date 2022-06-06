#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMainWindow>

class Button : public QPushButton
{

    Q_OBJECT

public:

    Button(int pox, int posy);

    void showButton();

};

#endif // BUTTON_H
