#include "RectangleItem.h"

#include <QPainter>

namespace ADVE {

RectangleItem::RectangleItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent)
    : CenterAndEdgePointItem(center, edge, parent)
{
}

QRectF RectangleItem::boundingRect() const
{
    QPointF center = m_center->m_point;
    QPointF edge   = m_edge->m_point;
    qreal width =  qAbs(center.x() - edge.x());
    qreal height =  qAbs(center.y() - edge.y());
    return QRectF(QPointF(-width, -height), QPointF(width, height));
}

void RectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawRect(this->boundingRect());
}

}
