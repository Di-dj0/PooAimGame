#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class button : public QPushButton
{

    Q_OBJECT

public:
    explicit button(QPushButton *parent = nullptr);

    button(int posx, int posy){
        setGeometry(posx, posy, 20, 20);
    };

    //erro q o stackoverflow arrumou
    virtual ~button() {};

};

#endif // BUTTON_H
