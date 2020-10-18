#ifndef CUSTOMTABLEWIDGET_H
#define CUSTOMTABLEWIDGET_H

#include <QTableWidget>
#include <QResizeEvent>


template <class T>
class myPair
{
    T a, b;
public:
    myPair(T first, T second)
    {
        a = first;
        b = second;
    }
    T getMAxLimit();

    void getMin();
};

template<class T>
T myPair<T>::getMAxLimit()
{
    T retval;
    retval = a>b?a:b;
    return retval;
}

template<class T>
void myPair<T>::getMin()
{
    int retval;
    retval = a>b?a:b;
}





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
