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
    virtual void focusInEvent(QFocusEvent* event) override;
    // 遍历所有子Item，当其指针对得上时，返回true。如果一个也对不上说明不是其子Item，返回false
    virtual bool isChildItem(QGraphicsItem* item);
    // 遍历所有子Item，然后调用hide()方。用户有自己想法可以重写该方法
    virtual void hideAllChild();
    // 遍历所有子Item，然后调用show()方法。用户有自己想法可以重写该方法
    virtual void showAllChild();
    // 除了某个Item之外，其他都show
    virtual void showChildExcept(QGraphicsItem* item);
    // 除了某个Item之外，其他都hide
    virtual void hideChildExcept(QGraphicsItem* item);

    // 成员变量:
    AtomPointItem* m_center;
    AtomPointItem* m_edge;

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
