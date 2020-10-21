#ifndef RESIZABLEWIDGET_H
#define RESIZABLEWIDGET_H

#include <QWidget>

class ResizableWidget : public QWidget
{
    Q_OBJECT
public:
	explicit ResizableWidget(QWidget *parent = nullptr);

protected:
	void resizeEvent(QResizeEvent *event) override;

signals:
	void sizeChanged();
};

#endif // RESIZABLEWIDGET_H
