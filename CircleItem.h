#ifndef CIRCLEITEM_H
#define CIRCLEITEM_H

#include "CenterAndEdgePointItem.h"

namespace ADVE {


class CircleItem : public CenterAndEdgePointItem
{
public:
    CircleItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent = nullptr);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected slots:
    virtual void edgeMove(QPointF difference) override;
};

}

#endif // CIRCLEITEM_H
