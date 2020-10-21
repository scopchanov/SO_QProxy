#include "ArrowItem.h"
#include "MovableItem.h"
#include "qmath.h"
#include <QRadioButton>
#include <QPainter>
#include <QPen>

ArrowItem::ArrowItem(QRadioButton *startItem, QRadioButton *endItem,
					 QGraphicsItem *parent) :
	QGraphicsLineItem(parent),
	m_startItem(startItem),
	m_endItem(endItem)
{
	setPen(QPen(QBrush(Qt::red), 2));
	updatePosition();

	connect(m_startItem->property("item").value<MovableItem *>(),
			&MovableItem::itemMoved, this, &ArrowItem::updatePosition);
	connect(m_endItem->property("item").value<MovableItem *>(),
			&MovableItem::itemMoved, this, &ArrowItem::updatePosition);
}

void ArrowItem::updatePosition()
{
	QPointF offset(7, 15);
	QPointF p1 = m_startItem->property("item").value<MovableItem *>()->pos()
				 + m_startItem->parentWidget()->mapToParent(m_startItem->pos())
				 + offset;
	QPointF p2 = m_endItem->property("item").value<MovableItem *>()->pos()
				 + m_endItem->parentWidget()->mapToParent(m_endItem->pos())
				 + offset;

	setLine(QLineF(p1, p2));
}

void ArrowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
					  QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setPen(pen());
	painter->drawLine(line());
	painter->restore();
}
