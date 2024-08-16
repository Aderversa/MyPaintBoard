#include "CircleItem.h"

#include <QPainter>
#include <QGraphicsScene>

namespace ADVE {

CircleItem::CircleItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent)
    :CenterAndEdgePointItem(center, edge, parent)
{
}

QRectF CircleItem::boundingRect() const
{
    QPointF edge   = m_edge->m_point;
    QPointF bottomRight(qAbs(edge.x()), qAbs(edge.y()));
    QPointF topLeft(-qAbs(edge.x()), -qAbs(edge.y()));
    return QRectF(topLeft, bottomRight);
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

void CircleItem::edgeMove(QPointF difference)
{
    m_edge->m_point = m_edge->m_point + difference;
    m_edge->m_point.setX((m_edge->m_point.x() + m_edge->m_point.y()) / qreal(2));
    m_edge->m_point.setY(m_edge->m_point.x());
    this->scene()->update();
}

}
