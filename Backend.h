#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class QGraphicsScene;
class QTableWidget;
class QRadioButton;
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
	QTableWidget *createTable(int type);
	void setupRosInitTable(QTableWidget *tableWidget);
	void setupImagesTable(QTableWidget *tableWidget);
	void setupPathTable(QTableWidget *tableWidget);
	void setupRosShutdownTable(QTableWidget *tableWidget);

	QGraphicsScene *m_scene;
	QRadioButton *m_startNode;
	QRadioButton *m_endNode;

private slots:
	void onInputRadioButton(bool checked);
	void onOutputRadioButton(bool checked);
};

#endif // BACKEND_H
