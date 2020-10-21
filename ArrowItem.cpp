#include "ArrowItem.h"
#include "qmath.h"
#include <QRadioButton>
#include <QPainter>
#include <QPen>
#include <QDebug>

ArrowItem::ArrowItem(QRadioButton *startItem, QRadioButton *endItem,
					 QGraphicsItem *parent) :
	QGraphicsLineItem(parent),
	m_startItem(startItem),
	m_endItem(endItem)
{
//	setFlag(QGraphicsItem::ItemIsSelectable, true);
	updatePosition();
}

void ArrowItem::updatePosition()
{
	qDebug() << m_startItem->mapToGlobal(m_startItem->pos());
	qDebug() << m_endItem->mapToGlobal(m_endItem->pos());

	QLineF line(mapFromScene(m_startItem->pos()), mapFromScene(m_endItem->pos()));
	setLine(line);
	update();
}

void ArrowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
					  QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)
	qDebug() << line();

	painter->save();
	painter->setPen(pen());
	painter->drawLine(line());
	painter->restore();
}
