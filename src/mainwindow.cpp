#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "laser_rev.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&aa,SIGNAL(SendRange()),this,SLOT(ShowRange()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowRange(void)
{
    QString distance;
    ui->progressBar->setValue(range_min/6*1000);
    ui->lcdNumber->display(range_min*1000);
    ui->label_2->setText("The minimum distance around the rplidar is "+distance.setNum(range_min*1000)+" mm");
}
