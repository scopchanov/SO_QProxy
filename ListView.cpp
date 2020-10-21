#include "ListView.h"
#include <QDrag>

ListView::ListView(QWidget *parent) : QListWidget(parent)
{
	setDragEnabled(true);
	setDropIndicatorShown(true);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setDefaultDropAction(Qt::CopyAction);
	setFrameStyle(QFrame::NoFrame);
	setViewMode(QListView::IconMode);
	setGridSize(QSize(64, 64));
	setMovement(QListView::Snap);
}

void ListView::startDrag(Qt::DropActions supportedActions)
{
	if (supportedActions & Qt::CopyAction) {
		const QList<QListWidgetItem *> &m_items(selectedItems());

		if (m_items.isEmpty())
			return;

		auto *data = mimeData(m_items);
		auto *drag = new QDrag(this);
		QPixmap pixmap("/home/labrat/QTrreeWidgetDragDtopToQListWidgetAndQGraphicsView/images/MyIcon_icon.png");

		drag->setPixmap(pixmap);
		drag->setMimeData(data);
		drag->setHotSpot(pixmap.rect().center());
		drag->exec(Qt::CopyAction);
	} else {
		QListWidget::startDrag(supportedActions);
	}
}

