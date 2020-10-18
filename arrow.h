#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

#include "diagramitem.h"


class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;


class Arrow : public QGraphicsLineItem
{
public:

    enum { Type = UserType + 4 };

    Arrow(DiagramItem *startItem, DiagramItem *endItem,
      QGraphicsItem *parent = nullptr);

    DiagramItem *startItem() const { return myStartItem; }
    DiagramItem *endItem() const { return myEndItem; }
    QPainterPath shape() const override;

    void setColor(const QColor &color) {
        myColor = color;
    }

    int type() const override { return Type; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QColor myColor;
    DiagramItem *myStartItem;
    DiagramItem *myEndItem;
    QPolygonF arrowHead;

};

#endif // ARROW_H
