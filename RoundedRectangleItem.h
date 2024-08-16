#ifndef ROUNDEDRECTANGLEITEM_H
#define ROUNDEDRECTANGLEITEM_H

#include "RectangleItem.h"

namespace ADVE {

class RoundedRectangleItem : public RectangleItem
{
public:
    RoundedRectangleItem(const QPointF& center, const QPointF& edge, RectangleItem* parent = nullptr);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected slots:
    void controlMove(QPointF difference);
    void controlFocusIn();
    void controlFocusOut();

protected:
    AtomPointItem* m_control;
    qreal m_dx = 0.0;
};

}

#endif // ROUNDEDRECTANGLEITEM_H
