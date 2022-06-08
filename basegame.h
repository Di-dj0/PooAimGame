#ifndef BASEGAME_H
#define BASEGAME_H

#include <QWidget>
#include <QMainWindow>
#include <QColor>
#include <QErrorMessage>
#include <vector>


class BaseGame : public QWidget
{
    Q_OBJECT

public:

    virtual void createButton() = 0;

    virtual void showButton() = 0;

public slots:

    virtual void nextButton() = 0;

};

#endif // BASEGAME_H
