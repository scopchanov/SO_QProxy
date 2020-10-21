#include "Backend.h"
#include "AppGlobals.h"
#include "MovableItem.h"
#include "ArrowItem.h"
#include "ListView.h"
#include <QBoxLayout>
#include <QSplitter>
#include <QGraphicsScene>
#include <QRadioButton>
#include <QTableWidget>
#include <QListWidgetItem>
#include <QDebug>

Backend::Backend(QObject *parent) :
	QObject(parent),
	m_scene(new QGraphicsScene(this)),
	m_startNode(nullptr),
	m_endNode(nullptr)
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

	item->addWidget(createTable(type, item));
}

QTableWidget *Backend::createTable(int type, MovableItem *item)
{
	auto *tableWidget = new QTableWidget;

	switch (type) {
	case IT_RosInit:
		setupRosInitTable(tableWidget, item);
		break;
	case IT_Images:
		setupImagesTable(tableWidget, item);
		break;
	case IT_Path:
		setupPathTable(tableWidget, item);
		break;
	case IT_RosShutDown:
		setupRosShutdownTable(tableWidget, item);
		break;
	}

	return tableWidget;
}

void Backend::setupRosInitTable(QTableWidget *tableWidget, MovableItem *item)
{
	tableWidget->setRowCount(1);
	tableWidget->setColumnCount(2);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			auto *btnOutput = new QRadioButton(tableWidget);

			btnOutput->setProperty("item", QVariant::fromValue(item));

			tableWidget->setItem(ridx, cidx, new QTableWidgetItem(QString("%1")
																  .arg(ridx)));
			tableWidget->setCellWidget(ridx, 1, btnOutput);

			connect(btnOutput, &QRadioButton::toggled,
					this, &Backend::onOutputRadioButton);
		}
	}
}

void Backend::setupImagesTable(QTableWidget *tableWidget, MovableItem *item)
{
	tableWidget->setRowCount(6);
	tableWidget->setColumnCount(6);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			auto *btnInput = new QRadioButton(tableWidget);
			auto *btnOutput = new QRadioButton(tableWidget);

			btnInput->setProperty("item", QVariant::fromValue(item));
			btnOutput->setProperty("item", QVariant::fromValue(item));

			tableWidget->setItem(ridx, cidx, new QTableWidgetItem(QString("%1")
																  .arg(ridx)));
			tableWidget->setCellWidget(ridx, 0, btnInput);
			tableWidget->setCellWidget(ridx, 5, btnOutput);

			connect(btnInput, &QRadioButton::toggled,
					this, &Backend::onInputRadioButton);
			connect(btnOutput, &QRadioButton::toggled,
					this, &Backend::onOutputRadioButton);
		}
	}
}

void Backend::setupPathTable(QTableWidget *tableWidget, MovableItem *item)
{
	tableWidget->setRowCount(4);
	tableWidget->setColumnCount(4);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			auto *btnInput = new QRadioButton(tableWidget);
			auto *btnOutput = new QRadioButton(tableWidget);

			btnInput->setProperty("item", QVariant::fromValue(item));
			btnOutput->setProperty("item", QVariant::fromValue(item));

			tableWidget->setItem(ridx, cidx, new QTableWidgetItem(QString("%1")
																  .arg(ridx)));
			tableWidget->setCellWidget(ridx, 0, btnInput);
			tableWidget->setCellWidget(ridx, 3, btnOutput);

			connect(btnInput, &QRadioButton::toggled,
					this, &Backend::onInputRadioButton);
			connect(btnOutput, &QRadioButton::toggled,
					this, &Backend::onOutputRadioButton);
		}
	}
}

void Backend::setupRosShutdownTable(QTableWidget *tableWidget, MovableItem *item)
{
	tableWidget->setRowCount(1);
	tableWidget->setColumnCount(2);

	for (int ridx = 0; ridx < tableWidget->rowCount(); ridx++) {
		for (int cidx = 0; cidx < tableWidget->columnCount(); cidx++) {
			QRadioButton *btnInput = new QRadioButton(tableWidget);
			QRadioButton *btnOutput = new QRadioButton(tableWidget);

			btnInput->setProperty("item", QVariant::fromValue(item));
			btnOutput->setProperty("item", QVariant::fromValue(item));

			tableWidget->setItem(ridx, cidx, new QTableWidgetItem(QString("%1")
																  .arg(ridx)));
			tableWidget->setCellWidget(ridx, 0, btnInput);
			tableWidget->setCellWidget(ridx, 1, btnOutput);

			connect(btnInput, &QRadioButton::toggled,
					this, &Backend::onInputRadioButton);
			connect(btnOutput, &QRadioButton::toggled,
					this, &Backend::onOutputRadioButton);
		}
	}
}

void Backend::onInputRadioButton(bool checked)
{
	m_endNode = checked ? static_cast<QRadioButton *>(sender()) : nullptr;

	if (m_startNode && m_endNode)
		m_scene->addItem(new ArrowItem(m_startNode, m_endNode));
}

void Backend::onOutputRadioButton(bool checked)
{
	m_startNode = checked ? static_cast<QRadioButton *>(sender()) : nullptr;

	if (m_startNode && m_endNode)
		m_scene->addItem(new ArrowItem(m_startNode, m_endNode));
}
