#include "EllipseItem.h"

#include <QPainter>
#include <QPen>

namespace ADVE {

EllipseItem::EllipseItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent)
    : CenterAndEdgePointItem(center, edge, parent)
{
}

QRectF EllipseItem::boundingRect() const
{
    QPointF center = m_center->m_point;
    QPointF edge   = m_edge->m_point;
    qreal width =  qAbs(center.x() - edge.x());
    qreal height =  qAbs(center.y() - edge.y());
    return QRectF(QPointF(-width, -height), QPointF(width, height));
}

void EllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawEllipse(this->boundingRect());
    this->drawBoundingRect(painter);
}

}

