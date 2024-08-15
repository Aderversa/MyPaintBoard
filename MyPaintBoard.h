#ifndef MYPAINTBOARD_H
#define MYPAINTBOARD_H

#include <QWidget>

class MyPaintBoard : public QWidget
{
    Q_OBJECT

public:
    MyPaintBoard(QWidget *parent = nullptr);
    ~MyPaintBoard();
};
#endif // MYPAINTBOARD_H
