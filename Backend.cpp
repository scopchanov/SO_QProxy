#include "Backend.h"
#include "AppGlobals.h"
#include "MovableItem.h"
#include "ListView.h"
#include <QBoxLayout>
#include <QSplitter>
#include <QGraphicsScene>
#include <QRadioButton>
#include <QTableWidget>
#include <QListWidgetItem>

Backend::Backend(QObject *parent) :
	QObject(parent),
	m_scene(new QGraphicsScene(this))
{

}

void Backend::setupList(ListView *listView)
{
	QHash<int, QString> hash;

	hash.insert(IT_RosInit, "ROS Init");
	hash.insert(IT_Images, "Images");
	hash.insert(IT_Path, "Path");
	hash.insert(IT_RosShutDown, "ROS Shutdown");

	for (int n = 0; n < hash.count(); n++) {
		auto *img = new QListWidgetItem(listView);

		img->setText(hash.value(n));
		img->setData(Qt::UserRole, n);
		img->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable
					  | Qt::ItemIsDragEnabled);

		listView->addItem(img);
	}
}

QGraphicsScene *Backend::scene() const
{
	return m_scene;
}

void Backend::onItemDropped(int type, const QPointF &pos)
{
	auto *item = new MovableItem();

	item->setPos(pos);
	m_scene->addItem(item);

	item->addWidget(createTable(type));
}

QTableWidget *Backend::createTable(int type)
{
	auto *tableWidget = new QTableWidget;

	switch (type) {
	case IT_RosInit:
		setupRosInitTable(tableWidget);
		break;
	case IT_Images:
		setupImagesTable(tableWidget);
		break;
	case IT_Path:
		setupPathTable(tableWidget);
		break;
	case IT_RosShutDown:
		setupRosShutdownTable(tableWidget);
		break;
	}

	return tableWidget;
}

void Backend::setupRosInitTable(QTableWidget *tableWidget)
{
	tableWidget->setColumnCount(2);
	tableWidget->setRowCount(1);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			auto *radioButton = new QRadioButton(tableWidget);

			tableWidget->setItem(ridx, cidx, new QTableWidgetItem(QString("%1").arg(ridx)));
			tableWidget->setCellWidget(cidx, 1, radioButton);

			// Before connecting the arrow let's make sure the connection between
			// QRadioButton and the subclassed QTableWidget is correct

			//QObject::connect(radio1, &QRadioButton::clicked, wgt, &MovableItem::itemMoved);
		}
	}
}

void Backend::setupImagesTable(QTableWidget *tableWidget)
{
	tableWidget->setColumnCount(6);
	tableWidget->setRowCount(6);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			auto *radio1 = new QRadioButton(tableWidget);
			auto *radio2 = new QRadioButton(tableWidget);
			auto *item = new QTableWidgetItem(QString("%1").arg(ridx));

			tableWidget->setItem(ridx,cidx,item);

			tableWidget->setCellWidget(cidx, 0, radio1);
			tableWidget->setCellWidget(cidx, 5, radio2);
		}
	}
}

void Backend::setupPathTable(QTableWidget *tableWidget)
{
	tableWidget->setColumnCount(4);
	tableWidget->setRowCount(4);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			auto *radio1 = new QRadioButton(tableWidget);
			auto *radio2 = new QRadioButton(tableWidget);
			auto* item = new QTableWidgetItem(QString("%1").arg(ridx));

			tableWidget->setItem(ridx,cidx,item);
			tableWidget->setCellWidget(cidx, 0, radio1);
			tableWidget->setCellWidget(cidx, 3, radio2);
		}
	}
}

void Backend::setupRosShutdownTable(QTableWidget *tableWidget)
{
	tableWidget->setColumnCount(2);
	tableWidget->setRowCount(1);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			QRadioButton *radio1 = new QRadioButton(tableWidget);
			QRadioButton *radio2 = new QRadioButton(tableWidget);
			auto* item = new QTableWidgetItem(QString("%1").arg(ridx));

			tableWidget->setItem(ridx,cidx,item);
			tableWidget->setCellWidget(cidx, 0, radio1);
			tableWidget->setCellWidget(cidx, 3, radio2);
		}
	}
}
