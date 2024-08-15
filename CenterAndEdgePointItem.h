#ifndef CENTERANDEDGEPOINTITEM_H
#define CENTERANDEDGEPOINTITEM_H

#include "AbstractShapeItem.h"
#include "AtomPointItem.h"

class QPainter;

namespace ADVE {


class CenterAndEdgePointItem : public AbstractShapeItem
{
public:
    CenterAndEdgePointItem(const QPointF& center, const QPointF& edge, AbstractShapeItem* parent = nullptr);

protected:
    // 函数
    virtual void drawBoundingRect(QPainter* painter);

    // 成员变量
    AtomPointItem* m_center;
    AtomPointItem* m_edge;
    QPen rectPen;

private slots:
    virtual void centerMove(QPointF difference);
    virtual void edgeMove(QPointF difference);
    void centerFocusIn();
    void edgeFocusIn();
    void centerFocusOut();
    void edgeFocusOut();
    // 使用rectPen和boundingRect()绘制Item的虚线矩形框
};

}


#endif // CENTERANDEDGEPOINTITEM_H
