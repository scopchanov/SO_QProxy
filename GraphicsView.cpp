#include "GraphicsView.h"
#include "AppGlobals.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent) :
	QGraphicsView(parent)
{
	setBackgroundBrush(QBrush(QPixmap(":/pix/images/20/grid.png")));
	setSceneRect(0, 0, 1000, 1000);
	setAlignment(Qt::AlignLeft | Qt::AlignTop);
	setFrameStyle(QFrame::NoFrame);
}

void GraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("application"
									 "/x-qabstractitemmodeldatalist"))
	  event->setAccepted(true);
}

void GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
	if (event->mimeData()->hasFormat("application"
									 "/x-qabstractitemmodeldatalist"))
	  event->setAccepted(true);
}

void GraphicsView::dropEvent(QDropEvent *event)
{

	QByteArray encoded = event->mimeData()->
						 data("application/x-qabstractitemmodeldatalist");
	QDataStream stream(&encoded, QIODevice::ReadOnly);
	QVector<int> rosTables;
	QString newString;

	while (!stream.atEnd()) {
		QMap<int, QVariant> roleDataMap;
		int row;
		int col;
		bool ok;

		stream >> row >> col >> roleDataMap;
		rosTables << roleDataMap[Qt::UserRole].toInt(&ok);
	}

	for (int tableType : rosTables)
		emit itemDropped(tableType, event->posF());
}
