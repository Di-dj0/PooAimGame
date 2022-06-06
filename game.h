#ifndef GAME_H
#define GAME_H

#include <QWindow>
#include <QTimer>
#include <vector>
#include "button.h"

class Game : public QWindow
{
    Q_OBJECT
    int qnt;
    static double score;
    std::vector<Button *> buttons;
    std::vector<Button *>::iterator it;
    QTimer *time = new QTimer();

public:
    //explicit Game(QWindow *parent = nullptr);

    Game(int qnt);

    void createButton();

    void showButton();

public slots:

    void nextButton();

signals:

    void gameEnd();

};

#endif // GAME_H
