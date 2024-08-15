#include "MyPaintBoard.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "CenterAndEdgePointItem.h"
#include "RectangleItem.h"
#include "EllipseItem.h"
#include "CircleItem.h"
#include "SquareItem.h"

int main(int argc, char *argv[])
{
    using namespace ADVE;
    QApplication a(argc, argv);
    SquareItem item(QPointF(0, 0), QPointF(40, 40)) ;
    QGraphicsScene scene;
    scene.addItem(&item);
    QGraphicsView view(&scene);
    view.show();
    return a.exec();
}
