#ifndef SQUAREITEM_H
#define SQUAREITEM_H

#include "CenterAndEdgePointItem.h"

namespace ADVE {

class SquareItem : public CenterAndEdgePointItem
{
public:
    SquareItem(const QPointF& center, const QPointF& edge, CenterAndEdgePointItem* parent = nullptr);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected slots:
    virtual void edgeMove(QPointF difference) override;
};

}

#endif // SQUAREITEM_H
