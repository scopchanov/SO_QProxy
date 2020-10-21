#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QListWidget>

class ListView : public QListWidget
{
	Q_OBJECT
public:
	explicit ListView(QWidget *parent = nullptr);

protected:
	void startDrag(Qt::DropActions supportedActions);
};

#endif // LISTVIEW_H
