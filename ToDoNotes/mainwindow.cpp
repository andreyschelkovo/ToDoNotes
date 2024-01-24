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
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    ui->listWidget
}

