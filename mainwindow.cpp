#include "MainWindow.h"
#include "GraphicsView.h"
#include "ListView.h"
#include "Backend.h"
#include <QBoxLayout>
#include <QSplitter>

MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent),
	m_backend(new Backend(this))
{
	auto *l = new QVBoxLayout(this);
	auto *listView = new ListView(this);
	auto *graphicsView = new GraphicsView(this);
	auto *splitter = new QSplitter(this);

	m_backend->setupList(listView);

	graphicsView->setScene(m_backend->scene());
	splitter->addWidget(listView);
	splitter->addWidget(graphicsView);

	l->addWidget(splitter);
	l->setContentsMargins(0, 0, 0, 0);

	connect(graphicsView, &GraphicsView::itemDropped,
			m_backend, &Backend::onItemDropped);

	resize(1000, 800);
}
