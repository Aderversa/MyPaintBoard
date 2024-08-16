#include "CenterAndEdgePointItem.h"
#include <QCursor>
#include <QDebug>
#include <QGraphicsScene>
#include <QPainter>
#include <QMutexLocker>

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
    connect(m_edge, &AtomPointItem::focusIn, this, &CenterAndEdgePointItem::edgeFocusIn);
    connect(m_edge, &AtomPointItem::focusOut, this, &CenterAndEdgePointItem::edgeFocusOut);

    m_edge->hide();
    m_center->hide();
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
    hideChildExcept(m_center);
}

void CenterAndEdgePointItem::centerFocusOut()
{
    showChildExcept(m_center);
    this->setFocus(Qt::MouseFocusReason);
}

void CenterAndEdgePointItem::edgeFocusIn()
{
    hideChildExcept(m_edge);
}

void CenterAndEdgePointItem::edgeFocusOut()
{
    showChildExcept(m_edge);
    this->setFocus(Qt::MouseFocusReason);
}


void CenterAndEdgePointItem::focusInEvent(QFocusEvent* event)
{
    AbstractShapeItem::focusInEvent(event);
    // 发生了focusInEvent()说明item所在的scene一定是存在的，所以这时才绑定信号和槽
    {
        // 使用同步机制保证connect只进行一次
        // 由于Qt::UniqueConnection无法对不是成员变量的this->scene()进行操作，所以只能出此下策
        // 但绑定完之后，保证再进行该connect操作，所以可以使用Q_UNLIKELY
        QMutexLocker lock(&focusChangedConnectedMutex);
        if (Q_UNLIKELY(!isFocusChangedConnected))
        {
            connect(this->scene(), &QGraphicsScene::focusItemChanged, this, &CenterAndEdgePointItem::focusChanged);
            isFocusChangedConnected = true;
        }
    }
    showAllChild();
}

void CenterAndEdgePointItem::focusChanged(QGraphicsItem* newFocusItem,
                                          QGraphicsItem* oldFocusItem,
                                          Qt::FocusReason reason)
{
    Q_UNUSED(reason);
    if (oldFocusItem == this)
    {
        if (!isChildItem(newFocusItem))
        {
            hideAllChild();
        }
    }
}

bool CenterAndEdgePointItem::isChildItem(QGraphicsItem* item)
{
    QList<QGraphicsItem*> childs = this->childItems();
    for (auto& child : childs)
    {
        if (child == item)
            return true;
    }
    return false;
}

void CenterAndEdgePointItem::hideAllChild()
{
    QList<QGraphicsItem*> childs = this->childItems();
    for (auto& child : childs)
    {
        child->hide();
    }
}

void CenterAndEdgePointItem::showAllChild()
{
    QList<QGraphicsItem*> childs = this->childItems();
    for (auto& child : childs)
    {
        child->show();
    }
}


void CenterAndEdgePointItem::showChildExcept(QGraphicsItem* item)
{
    QList<QGraphicsItem*> childs = this->childItems();
    for (auto& child : childs)
    {
        if (item != child)
        {
            child->show();
        }
    }
}

void CenterAndEdgePointItem::hideChildExcept(QGraphicsItem* item)
{
    QList<QGraphicsItem*> childs = this->childItems();
    for (auto& child : childs)
    {
        if (item != child)
        {
            child->hide();
        }
    }
}


} // End of ADVE
