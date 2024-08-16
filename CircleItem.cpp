#include "CircleItem.h"

#include <QPainter>

namespace ADVE {

CircleItem::CircleItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent)
    :CenterAndEdgePointItem(center, edge, parent)
{
}

QRectF CircleItem::boundingRect() const
{
    QPointF center = m_center->m_point;
    QPointF edge   = m_edge->m_point;
    qreal dx = center.x() - edge.x();
    qreal dy = center.y() - edge.y();
    qreal distance = qSqrt(qreal(dx * dx + dy * dy));
    return QRectF(QPointF(-distance, -distance), QPointF(distance, distance));
}

void CircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawEllipse(boundingRect());
    if(hasFocus())
        drawBoundingRect(painter);
}

}
