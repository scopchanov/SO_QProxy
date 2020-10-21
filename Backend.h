#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class QGraphicsScene;
class QTableWidget;
class QRadioButton;
class ListView;
class MovableItem;

class Backend : public QObject
{
	Q_OBJECT
public:
	explicit Backend(QObject *parent = nullptr);

	QGraphicsScene *scene() const;
	void setupList(ListView *listView);

public slots:
	void onItemDropped(int type, const QPointF &pos);

private:
	QTableWidget *createTable(int type, MovableItem *item);
	void setupRosInitTable(QTableWidget *tableWidget, MovableItem *item);
	void setupImagesTable(QTableWidget *tableWidget, MovableItem *item);
	void setupPathTable(QTableWidget *tableWidget, MovableItem *item);
	void setupRosShutdownTable(QTableWidget *tableWidget, MovableItem *item);

	QGraphicsScene *m_scene;
	QRadioButton *m_startNode;
	QRadioButton *m_endNode;

private slots:
	void onInputRadioButton(bool checked);
	void onOutputRadioButton(bool checked);
};

#endif // BACKEND_H
