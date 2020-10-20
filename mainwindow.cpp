#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mScene = new Scene;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setScene(mScene);
    ui->graphicsView->show();
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

