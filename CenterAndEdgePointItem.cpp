#include "CenterAndEdgePointItem.h"
#include <QCursor>
#include <QDebug>
#include <QGraphicsScene>
#include <QPainter>

namespace ADVE {

CenterAndEdgePointItem::CenterAndEdgePointItem(const QPointF& center, const QPointF& edge, AbstractShapeItem* parent)
    : AbstractShapeItem(parent)
    , m_center(new AtomPointItem(this, QPointF(0, 0), AtomPointItem::Circle))
    , m_edge(new AtomPointItem(this, QPointF(qAbs(center.x() - edge.x()), qAbs(center.y() - edge.y())), AtomPointItem::Square))
{
    // 设置在Scene中的坐标，m_center恒为父Item的坐标中心
    // 移动m_center会将其位置的变化传递给父Item(即本Item)处理
    this->setPos(center);

    m_center->setCursor(Qt::OpenHandCursor);
    m_center->setBrush(Qt::red);

    // m_edge是相对于m_center的坐标
    // 每当其坐标发生变换时
    m_edge->setCursor(Qt::PointingHandCursor);
    m_edge->setBrush(Qt::yellow);

    rectPen.setStyle(Qt::DashLine);
    rectPen.setColor(Qt::gray);

    connect(m_center, &AtomPointItem::pointMoved, this, &CenterAndEdgePointItem::centerMove);
    connect(m_edge, &AtomPointItem::pointMoved, this, &CenterAndEdgePointItem::edgeMove);
    connect(m_center, &AtomPointItem::focusIn, this, &CenterAndEdgePointItem::centerFocusIn);
    connect(m_center, &AtomPointItem::focusOut, this, &CenterAndEdgePointItem::centerFocusOut);
    connect(m_edge, &AtomPointItem::focusIn, this, &CenterAndEdgePointItem::centerFocusIn);
    connect(m_edge, &AtomPointItem::focusOut, this, &CenterAndEdgePointItem::centerFocusOut);
}


void CenterAndEdgePointItem::centerMove(QPointF difference)
{
    this->setPos(this->scenePos() + difference);
    this->scene()->update();
}

void CenterAndEdgePointItem::edgeMove(QPointF difference)
{
    m_edge->m_point = m_edge->m_point + difference;
    this->scene()->update();
}

void CenterAndEdgePointItem::centerFocusIn()
{

}

void CenterAndEdgePointItem::centerFocusOut()
{

}

void CenterAndEdgePointItem::edgeFocusIn()
{

}

void CenterAndEdgePointItem::edgeFocusOut()
{

}

void CenterAndEdgePointItem::drawBoundingRect(QPainter* painter)
{
    painter->setPen(rectPen);
    painter->drawRect(this->boundingRect());
}

}
