#include "scene.h"
#include "customtablewidget.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QTableWidget>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QMetaEnum>
#include <QEvent>
#include <QSizeGrip>

Scene::Scene(QObject *parent)
{
    setBackgroundBrush(Qt::lightGray);

}

void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
  if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    event->setAccepted(true);
}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event) {
  if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    event->setAccepted(true);
}

void Scene::dropEvent(QGraphicsSceneDragDropEvent *event) {
    QByteArray encoded =
      event->mimeData()->data("application/x-qabstractitemmodeldatalist");
    QDataStream stream(&encoded, QIODevice::ReadOnly);

    QStringList rosTables;
    QString newString;

    while (!stream.atEnd()) {
    int row, col;
    QMap<int, QVariant> roleDataMap;
    stream >> row >> col >> roleDataMap;
    rosTables << roleDataMap[Qt::DisplayRole].toString();
    }
    for (const QString &tableType : rosTables) {
        if(tableType == "Images")
        {
            QPoint initPos(0,0);
            CustomTableWidget *wgt = new CustomTableWidget;
            QGraphicsRectItem *proxyControl = addRect(initPos.x(), initPos.y(), wgt->width(), 20, QPen(Qt::black), QBrush(Qt::darkGreen)); // widget->width() works properly here because of the resize(layout->sizeHint()) that we have used inside it
            QSizeGrip * sizeGrip = new QSizeGrip(wgt);
            QHBoxLayout *layout = new QHBoxLayout(wgt);
            //QGraphicsRectItem *proxyControl = addRect(initPos.x(), initPos.y(), wgt->width(), 20, QPen(Qt::black), QBrush(Qt::darkGreen));

            layout->setContentsMargins(0, 0, 0, 0);
            layout->addWidget(sizeGrip, 0, Qt::AlignRight | Qt::AlignBottom);

            connect(wgt, &CustomTableWidget::sizeChanged, [wgt, proxyControl](){
                proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
            });

            proxyControl->setPos(initPos.x(), initPos.y());
            proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
            proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);

            wgt->setColumnCount(2);
            wgt->setRowCount(2);
            for (int ridx = 0 ; ridx < wgt->rowCount() ; ridx++ )
            {
                for (int cidx = 0 ; cidx < wgt->columnCount() ; cidx++)
                {
                    QTableWidgetItem* item = new QTableWidgetItem();
                    item->setText(QString("%1").arg(ridx));
                    wgt->setItem(ridx,cidx,item);
                }
            }
            QGraphicsProxyWidget * const proxy = addWidget(wgt);
            // In my case the rectangular graphics item is supposed to be above my widget so the position of the widget is shifted along the Y axis based on the height of the rectangle of that graphics item
            proxy->setPos(initPos.x(), initPos.y()+proxyControl->rect().height());
            proxy->setParentItem(proxyControl);
        }
    }
}
