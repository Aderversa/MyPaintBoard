#ifndef MYPAINTBOARD_H
#define MYPAINTBOARD_H

#include <QWidget>

class QPushButton;
class QGraphicsScene;
class QGraphicsView;
class QVBoxLayout;
class QGraphicsItem;

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
    void deleteFocusItem();
    void getLastFocusItem(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);

private:
    QPushButton* addCircleBtn;
    QPushButton* addEllipseBtn;
    QPushButton* addSquareBtn;
    QPushButton* addRectangleBtn;
    QPushButton* addRoundedRectangleBtn;
    QPushButton* deleteItemBtn;
    QGraphicsScene* scene;
    QGraphicsView*  view;
    QVBoxLayout* primeLayout;
    QGraphicsItem* lastFocusItem = nullptr;
};

}
#endif // MYPAINTBOARD_H
