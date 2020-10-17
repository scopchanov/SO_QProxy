#include "customtablewidget.h"

void CustomTableWidget::resizeEvent(QResizeEvent *event)
{
    QTableWidget::resizeEvent(event);

    emit sizeChanged();
}
