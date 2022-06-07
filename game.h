#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include <QMainWindow>
#include <QColor>
#include <QErrorMessage>
#include <vector>


class Game : public QWidget
{
    Q_OBJECT
    int qnt, tam, difficult, cor;


    std::vector<QPushButton *> buttons;
    std::vector<QPushButton *>::iterator it;
    QTimer *time;

public:
    //explicit Game(QWindow *parent = nullptr);
    static double score;

    Game(int qnt, int difficult,int cor);

    void createButton();

    void showButton();

    void setWindowGeometry(int x, int y, int w, int h);

public slots:

    void nextButton();

signals:

    void gameEnd();

};

#endif // GAME_H
