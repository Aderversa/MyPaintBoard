#include "MyPaintBoard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyPaintBoard w;
    w.show();
    return a.exec();
}
