#include "SquareItem.h"

#include <QPainter>
#include <QGraphicsScene>

namespace ADVE {

SquareItem::SquareItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent)
    : CenterAndEdgePointItem(center, edge, parent)
{
}

QRectF SquareItem::boundingRect() const
{
    QPointF edge   = m_edge->m_point;
    return QRectF(-edge, edge);
}

void SquareItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawRect(this->boundingRect());
}

void SquareItem::edgeMove(QPointF difference)
{
    m_edge->m_point = m_edge->m_point + difference;
    m_edge->m_point.setX((m_edge->m_point.x() + m_edge->m_point.y()) / qreal(2));
    m_edge->m_point.setY(m_edge->m_point.x());
    this->scene()->update();
}

}

