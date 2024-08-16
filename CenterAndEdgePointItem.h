#ifndef CENTERANDEDGEPOINTITEM_H
#define CENTERANDEDGEPOINTITEM_H

#include "AbstractShapeItem.h"
#include "AtomPointItem.h"
#include <QMutex>

class QPainter;

namespace ADVE {


class CenterAndEdgePointItem : public AbstractShapeItem
{
public:
    CenterAndEdgePointItem(const QPointF& center, const QPointF& edge, AbstractShapeItem* parent = nullptr);

protected:
    // 函数:
    // 使用rectPen和boundingRect()绘制Item的虚线矩形框
    virtual void drawBoundingRect(QPainter* painter);
    virtual void focusInEvent(QFocusEvent* event);

    // 成员变量:
    AtomPointItem* m_center;
    AtomPointItem* m_edge;
    QPen rectPen;

    QMutex focusChangedConnectedMutex;
    bool isFocusChangedConnected = false;

protected slots:
    // 当检测到鼠标移动事件后，会将鼠标的坐标变化作为信号发出
    // 本Item处理这些移动信号，子类可以通过重写这些方法实现不一样的移动逻辑
    virtual void centerMove(QPointF difference);
    virtual void edgeMove(QPointF difference);

    virtual void centerFocusIn();
    virtual void edgeFocusIn();
    virtual void centerFocusOut();
    virtual void edgeFocusOut();
    virtual void focusChanged(QGraphicsItem* newFocusItem, QGraphicsItem* oldFocusItem, Qt::FocusReason reason);

};

}


#endif // CENTERANDEDGEPOINTITEM_H
