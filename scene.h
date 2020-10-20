#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

#include "movableitem.h"

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent = nullptr);

protected:
  void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
  void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
  void dropEvent(QGraphicsSceneDragDropEvent *event);

private:
  MovableItem *mMovableItem;
};

#endif // SCENE_H
