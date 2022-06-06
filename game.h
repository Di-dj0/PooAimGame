#ifndef GAME_H
#define GAME_H

#include <QWindow>
#include <vector>
#include "button.h"

class game : public QWindow
{
    Q_OBJECT
    int /*shape,*/ difficult;
    double timer;
    std::vector<button> buttons;

public:
    explicit game(QWindow *parent = nullptr);

    game(/*int shape,*/ int difficult, double timer) : /*shape(shape),*/ difficult(difficult), timer(timer) {}

    void createButton(int qnt){
        int rand1, rand2;

        for(int i = 0; i < qnt; i++){
            rand1 = std::rand() % 350 + 600;
            rand2 = std::rand() % 100 + 600;
            //buttons.push_back(button(rand1, rand2));
        }
    }

signals:

};

#endif // GAME_H
