#ifndef RECTANGLEITEM_H
#define RECTANGLEITEM_H

#include "CenterAndEdgePointItem.h"

namespace ADVE {

class RectangleItem : public CenterAndEdgePointItem
{
public:
    RectangleItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent = nullptr);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}


#endif // RECTANGLEITEM_H
