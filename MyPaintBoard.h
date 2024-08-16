#ifndef MYPAINTBOARD_H
#define MYPAINTBOARD_H

#include <QWidget>

class QPushButton;
class QGraphicsScene;
class QGraphicsView;
class QVBoxLayout;

namespace ADVE {

class MyPaintBoard : public QWidget
{
    Q_OBJECT
public:
    MyPaintBoard(QWidget *parent = nullptr);
    ~MyPaintBoard();

private slots:
    void addCircle();
    void addEllipse();
    void addSquare();
    void addRectangle();
    void addRoundedRectangle();

private:
    QPushButton* addCircleBtn;
    QPushButton* addEllipseBtn;
    QPushButton* addSquareBtn;
    QPushButton* addRectangleBtn;
    QPushButton* addRoundedRectangleBtn;
    QGraphicsScene* scene;
    QGraphicsView*  view;
    QVBoxLayout* primeLayout;
};

}
#endif // MYPAINTBOARD_H
