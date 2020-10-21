#ifndef MOVABLEITEM_H
#define MOVABLEITEM_H

#include <QGraphicsPathItem>

class QVBoxLayout;

class MovableItem : public QObject, public QGraphicsPathItem
{
	Q_OBJECT
public:
	MovableItem(QGraphicsItem *parent = nullptr);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

	void addWidget(QWidget *widget);

private:
	QVBoxLayout *m_layout;

signals:
	void itemMoved(const QPointF &p);
};

#endif // MOVABLEITEM_H
