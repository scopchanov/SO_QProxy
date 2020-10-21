#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class QGraphicsScene;
class QTableWidget;
class ListView;

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
	QGraphicsScene *m_scene;

private:
	QTableWidget *createTable(int type);
	void setupRosInitTable(QTableWidget *tableWidget);
	void setupImagesTable(QTableWidget *tableWidget);
	void setupPathTable(QTableWidget *tableWidget);
	void setupRosShutdownTable(QTableWidget *tableWidget);
};

#endif // BACKEND_H
