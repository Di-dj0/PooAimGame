#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QPainter>

class Button : public QPushButton
{

    Q_OBJECT

public:

    Button(int posx, int posy);

    void showButton();

};

#endif // BUTTON_H
