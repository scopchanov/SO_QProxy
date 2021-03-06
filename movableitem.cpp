#include "MovableItem.h"
#include "ResizableWidget.h"
#include <QBoxLayout>
#include <QSizeGrip>
#include <QGraphicsProxyWidget>
#include <QPen>

MovableItem::MovableItem(QGraphicsItem *parent) :
	QGraphicsRectItem(parent),
	m_layout(new QVBoxLayout())
{
	auto *wgt = new ResizableWidget;
	auto *sizeGrip = new QSizeGrip(wgt);
	auto *layoutProxy = new QHBoxLayout(wgt);
	auto *proxy = new QGraphicsProxyWidget(this);

	layoutProxy->addLayout(m_layout);
	layoutProxy->addWidget(sizeGrip, 0, Qt::AlignRight | Qt::AlignBottom);
	layoutProxy->setContentsMargins(0, 0, 0, 0);

	connect(wgt, &ResizableWidget::sizeChanged, [this, wgt](){
		setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
	});

	proxy->setPos(10, 10);
	proxy->setParentItem(this);
	proxy->setWidget(wgt);

	setPen(QPen(Qt::black));
	setBrush(QBrush(Qt::darkGreen));
	setFlags(ItemIsFocusable | ItemIsMovable | ItemIsSelectable
			 | ItemSendsGeometryChanges);
	setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
}

QVariant MovableItem::itemChange(QGraphicsItem::GraphicsItemChange change,
								 const QVariant &value)
{
	if (change == ItemPositionChange && scene())
		emit itemMoved(value.toPointF());

	return QGraphicsItem::itemChange(change, value);
}

void MovableItem::addWidget(QWidget *widget)
{
	m_layout->addWidget(widget);
}
