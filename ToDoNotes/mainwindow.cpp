#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Add_New_btn_clicked()
{

    QTreeWidgetItem *rootnamecompany = new QTreeWidgetItem(ui->treeWidget);
    rootnamecompany->setData(0,Qt::DisplayRole,ui->lineEdit->text());
    ui->treeWidget->addTopLevelItem(rootnamecompany);
    QTreeWidgetItem *child = new QTreeWidgetItem();
    child->setText(0,"qwerty");
    rootnamecompany->addChild(child);

    ui->lineEdit->clear();
}



void MainWindow::on_pushButton_clicked()
{


}

