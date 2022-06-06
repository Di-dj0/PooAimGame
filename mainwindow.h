#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include "game.h"
#include "button.h"
#include <QTimer>

class mainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *game1_button, *game2_button;
    game *game1Window, *game2Window;
    QInputDialog *userInput;
public:
    explicit mainWindow(QWidget *parent = nullptr);

public slots:
    void miniGame1();
    void miniGame2();

signals:

};

#endif // MAINWINDOW_H
