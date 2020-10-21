#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QGraphicsLineItem>

class QRadioButton;

class ArrowItem : public QObject, public QGraphicsLineItem
{
	Q_OBJECT
public:

	enum { Type = UserType + 4 };

	ArrowItem(QRadioButton *startItem, QRadioButton *endItem,
			  QGraphicsItem *parent = nullptr);

	QRadioButton *startItem() const { return m_startItem; }
	QRadioButton *endItem() const { return m_endItem; }

	int type() const override { return Type; }

	void updatePosition();

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			   QWidget *widget = nullptr) override;

private:
	QRadioButton *m_startItem;
	QRadioButton *m_endItem;
};

#endif // ARROWITEM_H
