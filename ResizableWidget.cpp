#include "ResizableWidget.h"

ResizableWidget::ResizableWidget(QWidget *parent) :
	QWidget(parent)
{

}

void ResizableWidget::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);

	emit sizeChanged();
}
