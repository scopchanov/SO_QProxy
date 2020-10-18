#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPolygonItem>

class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;

class Arrow;


class DiagramItem : public QGraphicsPolygonItem
{
public:

    DiagramItem(QMenu *contextMenu, QGraphicsItem *parent = Q_NULLPTR);

    void removeArrow(Arrow *arrow);
    void removeArrows();
    void addArrow(Arrow *arrow);

    QPixmap image() const;


protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;


private:
    QPolygonF myPolygon;
    QList<Arrow*> arrows;
    QMenu *myContextMenu;


};


#endif // DIAGRAMITEM_H
