#ifndef ABSTRACTSHAPEITEM_H
#define ABSTRACTSHAPEITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QObject>
#include <QPen>

namespace ADVE {

class AtomPointItem;

class AbstractShapeItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT
public:
    AbstractShapeItem(QAbstractGraphicsShapeItem* parent = nullptr);

protected:
    virtual void focusInEvent(QFocusEvent* event) override;
    virtual void focusOutEvent(QFocusEvent* event) override;
    // 使用rectPen和boundingRect()绘制Item的虚线矩形框
    virtual void drawBoundingRect(QPainter* painter);

    QPen rectPen;

private:
    QPen m_pen_isSelected;
    QPen m_pen_noSelected;
};

}

#endif // ABSTRACTSHAPEITEM_H
