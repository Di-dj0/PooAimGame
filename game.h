#ifndef GAME_H
#define GAME_H

#include "basegame.h"

class Game : public BaseGame
{
    Q_OBJECT
    int qnt, tam, difficult, cor;

    std::vector<QPushButton *> buttons;
    std::vector<QPushButton *>::iterator it;
    QTimer *time;



public:
    static double score;

    Game(int qnt, int difficult, int cor);

    void createButton();

    void showButton();

public slots:

    void nextButton();

signals:

    void gameEnd();

};

#endif // GAME_H
