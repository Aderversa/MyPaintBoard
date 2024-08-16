#include "MyPaintBoard.h"
#include "CircleItem.h"
#include "SquareItem.h"
#include "EllipseItem.h"
#include "RectangleItem.h"
#include "RoundedRectangleItem.h"

#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace ADVE {

MyPaintBoard::MyPaintBoard(QWidget *parent)
    : QWidget(parent)
    , addCircleBtn(new QPushButton(tr("圆形"), this))
    , addEllipseBtn(new QPushButton(tr("椭圆"), this))
    , addSquareBtn(new QPushButton(tr("正方形"), this))
    , addRectangleBtn(new QPushButton(tr("矩形"), this))
    , addRoundedRectangleBtn(new QPushButton(tr("圆角矩形"), this))
    , scene(new QGraphicsScene())
    , view(new QGraphicsView(scene))
    , primeLayout(new QVBoxLayout(this))
{
    scene->setSceneRect(0, 0, 1024, 512);
    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(addCircleBtn);
    buttonsLayout->addWidget(addEllipseBtn);
    buttonsLayout->addWidget(addSquareBtn);
    buttonsLayout->addWidget(addRectangleBtn);
    buttonsLayout->addWidget(addRoundedRectangleBtn);
    primeLayout->addLayout(buttonsLayout);
    primeLayout->addWidget(view);


    connect(addCircleBtn, &QPushButton::clicked, this, &MyPaintBoard::addCircle);
    connect(addEllipseBtn, &QPushButton::clicked, this, &MyPaintBoard::addEllipse);
    connect(addSquareBtn, &QPushButton::clicked, this, &MyPaintBoard::addSquare);
    connect(addRectangleBtn, &QPushButton::clicked, this, &MyPaintBoard::addRectangle);
    connect(addRoundedRectangleBtn, &QPushButton::clicked, this, &MyPaintBoard::addRoundedRectangle);

    view->show();
}

MyPaintBoard::~MyPaintBoard()
{
    if(view)
        delete view;
    if(scene)
        delete scene;
}


void MyPaintBoard::addCircle()
{
    CircleItem* item = new CircleItem(QPointF(0, 0), QPointF(20, 20));
    scene->addItem(item);
}

void MyPaintBoard::addEllipse()
{
    EllipseItem* item = new EllipseItem(QPointF(0, 0), QPointF(20, 20));
    scene->addItem(item);
}

void MyPaintBoard::addSquare()
{
    SquareItem* item = new SquareItem(QPointF(0, 0), QPointF(20, 20));
    scene->addItem(item);
}

void MyPaintBoard::addRectangle()
{
    RectangleItem* item = new RectangleItem(QPointF(0, 0), QPointF(20, 20));
    scene->addItem(item);
}

void MyPaintBoard::addRoundedRectangle()
{
    RoundedRectangleItem* item = new RoundedRectangleItem(QPointF(0, 0), QPointF(20, 20));
    scene->addItem(item);
}

}
