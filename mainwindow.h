#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <QWindow>
#include <QTimer>

class mainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *minigame1, *minigame2;
    QInputDialog *userInput;
    QWindow *game1;
public:
    explicit mainWindow(QWidget *parent = nullptr);

public slots:
    void pequenoJogo1();
    void pequenoJogo2();

signals:

};

#endif // MAINWINDOW_H
