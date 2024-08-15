#include "AtomPointItem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

namespace ADVE{

AtomPointItem::AtomPointItem(QAbstractGraphicsShapeItem* parent, const QPointF& point, PointType type)
    : QAbstractGraphicsShapeItem(parent)
    , m_point(point)
    , m_type(type)
{
    this->setPos(m_point);
    // 不可以是Movable，因为如果Movable那么父类的mouseMoveEvent的逻辑跟我们的有矛盾
    this->setFlags(QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsFocusable);
}

QRectF AtomPointItem::boundingRect() const
{
    return QRectF(-4, -4, 8, 8);
}

void AtomPointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    this->setPos(m_point);
    switch(m_type)
    {
    case Circle:
        painter->drawEllipse(boundingRect());
        break;
    case Square:
        painter->drawRect(boundingRect());
        break;
    default: break;
    }
}

void AtomPointItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseMoveEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        QPointF difference;
        difference.setX(event->scenePos().x() - event->lastScenePos().x());
        difference.setY(event->scenePos().y() - event->lastScenePos().y());
        emit pointMoved(difference);
    }
}

void AtomPointItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    emit focusIn();
}

void AtomPointItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    emit focusOut();
}

}
