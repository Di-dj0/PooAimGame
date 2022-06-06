#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{

    Q_OBJECT

public:

    Button(int posx, int posy){
        setGeometry(posx, posy, 20, 20);
    }

    virtual ~Button() {}

};

#endif // BUTTON_H
