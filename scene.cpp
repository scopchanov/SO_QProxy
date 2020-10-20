#include "scene.h"
#include "customtablewidget.h"
#include "arrow.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QTableWidget>
#include <QGraphicsProxyWidget>
#include <QVBoxLayout>
#include <QMetaEnum>
#include <QEvent>
#include <QSizeGrip>
#include <QRadioButton>


Scene::Scene(QObject *parent)
{
    setBackgroundBrush(Qt::lightGray);
    setSceneRect(0, 0, 1000, 1000);
    Q_UNUSED(parent)
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
    for (const QString &tableType : rosTables)
    {
        if (tableType == "ROS Init")
        {
            QPoint initPos(0, 0);
            auto *wgt = new CustomTableWidget;
            auto *proxyControl = addRect(0, 0, 0, 0, QPen(Qt::black),
                                         QBrush(Qt::darkGreen));

            auto *sizeGrip = new QSizeGrip(wgt);
            auto *layout = new QHBoxLayout(wgt);

            layout->setContentsMargins(0, 0, 0, 0);
            layout->addWidget(sizeGrip, 0, Qt::AlignRight | Qt::AlignBottom);

            connect(wgt, &CustomTableWidget::sizeChanged, [wgt, proxyControl](){
                proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
            });

            wgt->setColumnCount(2);
            wgt->setRowCount(1);

            for (int ridx = 0; ridx < wgt->rowCount(); ridx++) {
                for (int cidx = 0; cidx < wgt->columnCount(); cidx++) {
                    QRadioButton *radio1, *radio2;
                    auto* item = new QTableWidgetItem();
                    item->setText(QString("%1").arg(ridx));
                    wgt->setItem(ridx,cidx,item);
                    radio1 = new QRadioButton;
                    wgt->setCellWidget(cidx, 1, radio1);

                    // Before connecting the arrow let's make sure the connection between
                    // QRadioButton and the subclassed QTableWidget is correct

                    //QObject::connect(radio1, &QRadioButton::clicked, wgt, &MovableItem::itemMoved);
                }
            }

            auto *const proxy = addWidget(wgt);

            //proxy->setPos(initPos.x(), initPos.y()+ proxyControl->rect().height());

            proxy->setPos(10, 10);
            proxy->setParentItem(proxyControl);

            proxyControl->setPos(initPos.x(), initPos.y());
            proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
            proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
            proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
        }
        else if(tableType == "Images")
        {
            QPoint initPos(0, 0);
            auto *wgt = new CustomTableWidget;
            auto *proxyControl = addRect(0, 0, 0, 0, QPen(Qt::black),
                                         QBrush(Qt::darkGreen));

            auto *sizeGrip = new QSizeGrip(wgt);
            auto *layout = new QHBoxLayout(wgt);

            layout->setContentsMargins(0, 0, 0, 0);
            layout->addWidget(sizeGrip, 0, Qt::AlignRight | Qt::AlignBottom);

            connect(wgt, &CustomTableWidget::sizeChanged, [wgt, proxyControl](){
                proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
            });

            wgt->setColumnCount(6);
            wgt->setRowCount(6);

            for (int ridx = 0; ridx < wgt->rowCount(); ridx++) {
                for (int cidx = 0; cidx < wgt->columnCount(); cidx++) {
                    QRadioButton *radio1, *radio2;
                    auto* item = new QTableWidgetItem();
                    item->setText(QString("%1").arg(ridx));
                    wgt->setItem(ridx,cidx,item);
                    radio1 = new QRadioButton;
                    radio2 = new QRadioButton;
                    wgt->setCellWidget(cidx, 0, radio1);
                    wgt->setCellWidget(cidx, 5, radio2);
                }
            }

            auto *const proxy = addWidget(wgt);

            //proxy->setPos(initPos.x(), initPos.y()+ proxyControl->rect().height());

            proxy->setPos(10, 10);
            proxy->setParentItem(proxyControl);

            proxyControl->setPos(initPos.x(), initPos.y());
            proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
            proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
            proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));

        }
        else if(tableType == "Path")
        {
            QPoint initPos(0, 0);
            auto *wgt = new CustomTableWidget;
            auto *proxyControl = addRect(0, 0, 0, 0, QPen(Qt::black),
                                         QBrush(Qt::darkGreen));

            auto *sizeGrip = new QSizeGrip(wgt);
            auto *layout = new QHBoxLayout(wgt);

            layout->setContentsMargins(0, 0, 0, 0);
            layout->addWidget(sizeGrip, 0, Qt::AlignRight | Qt::AlignBottom);

            connect(wgt, &CustomTableWidget::sizeChanged, [wgt, proxyControl](){
                proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
            });

            wgt->setColumnCount(4);
            wgt->setRowCount(4);

            for (int ridx = 0; ridx < wgt->rowCount(); ridx++) {
                for (int cidx = 0; cidx < wgt->columnCount(); cidx++) {
                    QRadioButton *radio1, *radio2;
                    auto* item = new QTableWidgetItem();
                    item->setText(QString("%1").arg(ridx));
                    wgt->setItem(ridx,cidx,item);
                    radio1 = new QRadioButton;
                    radio2 = new QRadioButton;
                    wgt->setCellWidget(cidx, 0, radio1);
                    wgt->setCellWidget(cidx, 3, radio2);
                }
            }

            auto *const proxy = addWidget(wgt);

            //proxy->setPos(initPos.x(), initPos.y()+ proxyControl->rect().height());

            proxy->setPos(10, 10);
            proxy->setParentItem(proxyControl);

            proxyControl->setPos(initPos.x(), initPos.y());
            proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
            proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
            proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
        } else if(tableType == "ROS Shutdown") {
                QPoint initPos(0, 0);
                auto *wgt = new CustomTableWidget;
                auto *proxyControl = addRect(0, 0, 0, 0, QPen(Qt::black),
                                             QBrush(Qt::darkGreen));

                auto *sizeGrip = new QSizeGrip(wgt);
                auto *layout = new QHBoxLayout(wgt);

                layout->setContentsMargins(0, 0, 0, 0);
                layout->addWidget(sizeGrip, 0, Qt::AlignRight | Qt::AlignBottom);

                connect(wgt, &CustomTableWidget::sizeChanged, [wgt, proxyControl](){
                    proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
                });

                wgt->setColumnCount(2);
                wgt->setRowCount(1);

                for (int ridx = 0; ridx < wgt->rowCount(); ridx++) {
                    for (int cidx = 0; cidx < wgt->columnCount(); cidx++) {
                        QRadioButton *radio1, *radio2;
                        auto* item = new QTableWidgetItem();
                        item->setText(QString("%1").arg(ridx));
                        wgt->setItem(ridx,cidx,item);
                        radio1 = new QRadioButton;
                        radio2 = new QRadioButton;
                        wgt->setCellWidget(cidx, 0, radio1);
                        wgt->setCellWidget(cidx, 3, radio2);
                    }
                }

                auto *const proxy = addWidget(wgt);

                //proxy->setPos(initPos.x(), initPos.y()+ proxyControl->rect().height());

                proxy->setPos(10, 10);
                proxy->setParentItem(proxyControl);

                proxyControl->setPos(initPos.x(), initPos.y());
                proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
                proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
                proxyControl->setRect(wgt->geometry().adjusted(-10, -10, 10, 10));
        }
    }
}
