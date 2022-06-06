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
    double timeLimit;

    std::vector<Button *> buttons;
    std::vector<Button *>::iterator it;
    QTimer *time = new QTimer();

public:
    //explicit Game(QWindow *parent = nullptr);
    static double score;

    Game(int qnt);

    Game(double timeLimit);

    void createButton();

    void showButton();

    void setWindowGeometry(int x, int y, int w, int h);

public slots:

    void nextButton();

signals:

    void gameEnd();

};

#endif // GAME_H
