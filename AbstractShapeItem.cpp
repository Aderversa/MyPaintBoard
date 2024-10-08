#include "AbstractShapeItem.h"
#include <QPainter>

namespace ADVE{

AbstractShapeItem::AbstractShapeItem(QAbstractGraphicsShapeItem* parent)
    :QAbstractGraphicsShapeItem(parent)
{
    m_pen_noSelected.setColor(QColor(0, 160, 230));
    m_pen_noSelected.setWidth(2);
    m_pen_isSelected.setColor(QColor(255, 0, 255));
    m_pen_isSelected.setWidth(2);

    this->setPen(m_pen_noSelected);
    this->setFlags(QGraphicsItem::ItemIsSelectable |
                   QGraphicsItem::ItemIsFocusable  |
                   QGraphicsItem::ItemIsMovable);
}

void AbstractShapeItem::focusInEvent(QFocusEvent* event)
{
    QAbstractGraphicsShapeItem::focusInEvent(event);
    this->setPen(m_pen_isSelected);
}

void AbstractShapeItem::focusOutEvent(QFocusEvent* event)
{
    QAbstractGraphicsShapeItem::focusOutEvent(event);
    this->setPen(m_pen_noSelected);
}

void AbstractShapeItem::drawBoundingRect(QPainter* painter)
{
    painter->setPen(rectPen);
    painter->drawRect(this->boundingRect());
}

}
