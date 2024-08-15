#ifndef ATOMPOINTITEM_H
#define ATOMPOINTITEM_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>

namespace ADVE {


class AtomPointItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT
public:
    enum PointType {
        Circle = 0,
        Square
    };
    QPointF m_point;
    AtomPointItem(QAbstractGraphicsShapeItem* parent, const QPointF& point, PointType type);
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void pointMoved(QPointF difference);
    void focusIn();
    void focusOut();

private:
    PointType m_type;
};

}


#endif // ATOMPOINTITEM_H
