#include "RoundedRectangleItem.h"

#include <QCursor>
#include <QPainter>
#include <QGraphicsScene>

namespace ADVE {

RoundedRectangleItem::RoundedRectangleItem(const QPointF& center, const QPointF& edge, RectangleItem* parent)
    : RectangleItem(center, edge, parent)
    , m_control(new AtomPointItem(this, QPointF(m_edge->m_point.x(), -m_edge->m_point.y()), AtomPointItem::Square))
{
    m_control->setCursor(Qt::PointingHandCursor);
    m_control->setBrush(Qt::green);
    m_control->hide();

    connect(m_control, &AtomPointItem::pointMoved, this, &RoundedRectangleItem::controlMove);
    connect(m_control, &AtomPointItem::focusIn, this, &RoundedRectangleItem::controlFocusIn);
    connect(m_control, &AtomPointItem::focusOut, this, &RoundedRectangleItem::controlFocusOut);
}

QRectF RoundedRectangleItem::boundingRect() const
{
    QPointF center = m_center->m_point;
    QPointF edge   = m_edge->m_point;
    qreal width =  qAbs(center.x() - edge.x());
    qreal height =  qAbs(center.y() - edge.y());
    return QRectF(QPointF(-width, -height), QPointF(width, height));
}

void RoundedRectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    QRectF rect = boundingRect();
    qreal radius = rect.right() - m_control->m_point.x();
    qreal doubleRadius = 2 * radius;
    QRectF topLeftRect = QRectF(rect.topLeft(), rect.topLeft() + QPointF(doubleRadius, doubleRadius));
    QRectF topRightRect = QRectF(QPointF(rect.right() - doubleRadius, rect.top()), QPointF(rect.right(), rect.top() + doubleRadius));
    QRectF bottomLeftRect = QRectF(QPointF(rect.left(), rect.bottom() - doubleRadius), QPointF(rect.left() + doubleRadius, rect.bottom()));
    QRectF bottomRightRect = QRectF(rect.bottomRight() - QPointF(doubleRadius, doubleRadius), rect.bottomRight());
    painter->drawArc(topLeftRect, 90 * 16, 90 * 16);
    painter->drawArc(topRightRect, 0, 90 * 16);
    painter->drawArc(bottomRightRect, 0, -90 * 16);
    painter->drawArc(bottomLeftRect, -90 * 16, -90 * 16);
    // 上面的直线
    QPointF p1(rect.left() + radius, rect.top());
    QPointF p2(rect.right() - radius, rect.top());
    painter->drawLine(p1, p2);
    // 右边的直线
    p1 = QPointF(rect.right(), rect.top() + radius);
    p2 = QPointF(rect.right(), rect.bottom() - radius);
    painter->drawLine(p1, p2);
    // 下边的直线
    p1 = QPointF(rect.right() - radius, rect.bottom());
    p2 = QPointF(rect.left() + radius, rect.bottom());
    painter->drawLine(p1, p2);
    // 左边的直线
    p1 = QPointF(rect.left(), rect.bottom() - radius);
    p2 = QPointF(rect.left(), rect.top() + radius);
    painter->drawLine(p1, p2);

    if (hasFocus())
        drawBoundingRect(painter);
}

void RoundedRectangleItem::controlMove(QPointF difference)
{
    QRectF rect = this->boundingRect();
    QPointF tmpPoint = m_control->m_point;
    m_control->m_point = m_control->m_point + difference;
    qDebug() << QString("dx=%1, dy=%2").arg(difference.x()).arg(difference.y());

    // m_control是一个位于矩形右上角用于控制矩形的圆角程度的点。
    // minLeft是通过数学方式计算出来的m_control的最左边坐标
    qreal minLeft = rect.right() - qreal(qMin(rect.height(), rect.width()) / 2);

    // 圆角圆心到长边和宽边的距离都为radius
    qreal radius = rect.right() - m_control->m_point.x();

    // 设置成1.5倍radius是为了防止四个角完全变成圆形
    // 倍数越高，定点角能达到的最圆程度就越少。最少不能小于1倍，否则会出现错误绘图
    if (rect.right() - radius <= minLeft)
    {
        if (difference.x() < 0) { // m_control的x坐标已经处于最小值minLeft了，则不变
            // 这是为了防止浮点数误差带来的m_control抖动
            m_control->m_point = tmpPoint;
            return;
        }
        m_control->m_point.setX(minLeft + radius);
    }
    qDebug() << QString("x=%1, right=%2").arg(m_control->m_point.x()).arg(rect.right());
    if (m_control->m_point.x() > rect.right())
    {
        m_control->m_point.setX(rect.right());
    }
    m_control->m_point.setY(boundingRect().top());
    this->scene()->update();
}

void RoundedRectangleItem::controlFocusIn()
{
    hideChildExcept(m_control);
}

void RoundedRectangleItem::controlFocusOut()
{
    showChildExcept(m_control);
    this->setFocus(Qt::MouseFocusReason);
}

void RoundedRectangleItem::edgeMove(QPointF difference)
{
    qreal dx = qAbs(difference.x());
    qreal dy = qAbs(difference.y());
    qreal radius = boundingRect().right() - m_control->m_point.x();
    if (difference.x() < 0) {
        qreal xMinDiff = boundingRect().width() / 2 - radius;
        dx = -qMin(xMinDiff, dx);
    }
    if (difference.y() < 0) {
        qreal yMinDiff = boundingRect().height() / 2 - radius;
        dy = -qMin(yMinDiff, dy);
    }
    m_edge->m_point = m_edge->m_point + QPointF(dx, dy);
    // m_control也需要进行移动

    m_control->m_point += QPointF(dx, -dy);
    this->scene()->update();
}

}
