#ifndef ABSTRACTSHAPEITEM_H
#define ABSTRACTSHAPEITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QObject>
#include <QPen>

namespace ADVE {

class AbstractShapeItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT
public:
    enum ItemType {
        Ellipse = 0,
        Rectangle,
        Circle,
        Square
    };
    AbstractShapeItem(ItemType type);
    ItemType getItemType() { return m_type; }

protected:
    virtual void focusInEvent(QFocusEvent* event) override;
    virtual void focusOutEvent(QFocusEvent* event) override;

private:
    ItemType m_type;
    QPen m_pen_isSelected;
    QPen m_pen_noSelected;
};

}

#endif // ABSTRACTSHAPEITEM_H
