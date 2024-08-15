#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include "CenterAndEdgePointItem.h"

namespace ADVE {

class EllipseItem : public CenterAndEdgePointItem
{
public:
    EllipseItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent = nullptr);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}

#endif // ELLIPSEITEM_H
