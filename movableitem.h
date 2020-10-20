#ifndef MOVABLEITEM_H
#define MOVABLEITEM_H

#include <QGraphicsPathItem>


class MovableItem : public QGraphicsPathItem
{
public:
    MovableItem(QWidget *parent = Q_NULLPTR);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

signals:
    void itemMoved(const QPoint &p);

};

#endif // MOVABLEITEM_H
