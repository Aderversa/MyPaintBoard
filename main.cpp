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
    MyPaintBoard w;
    w.show();
    return a.exec();
}
