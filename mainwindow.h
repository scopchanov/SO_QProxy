#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Backend;

class MainWindow : public QWidget {

	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	Backend *m_backend;
};

#endif // MAINWINDOW_H
