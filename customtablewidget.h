#ifndef CUSTOMTABLEWIDGET_H
#define CUSTOMTABLEWIDGET_H

#include <QTableWidget>
#include <QResizeEvent>


class CustomTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    CustomTableWidget(QWidget *parent = Q_NULLPTR) : QTableWidget(parent){}
    void resizeEvent(QResizeEvent *event);

signals:
    void sizeChanged();

};

#endif // CUSTOMTABLEWIDGET_H
