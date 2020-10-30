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
	if (event->mimeData()->hasFormat("text/plain"))
	  event->setAccepted(true);
}

void GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
	if (event->mimeData()->hasFormat("text/plain"))
	  event->setAccepted(true);
}

void GraphicsView::dropEvent(QDropEvent *event)
{
	emit itemDropped(event->mimeData()->data("text/plain").toInt(), event->posF());
}
