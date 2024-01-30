#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Date = Date.currentDate();

}

MainWindow::~MainWindow()
{
    delete ui;
}


//////////////////////////////Secirities
///
void MainWindow::on_Add_New_btn_clicked()
{
    this->rootnamecompany = new QTreeWidgetItem(ui->treeWidget);
    rootnamecompany->setData(0,Qt::DisplayRole,ui->lineEdit_company->text());
    ui->treeWidget->addTopLevelItem(rootnamecompany);


    ui->lineEdit_company->clear();
}



void MainWindow::on_Save_Price_btn_clicked()
{
    QTreeWidgetItem *child = new QTreeWidgetItem();
    QTreeWidgetItem *current_company;
    current_company = ui->treeWidget->currentItem();
    child->setText(1,Date.toString("dd.MM.yyyy"));
    child->setText(2,ui->lineEdit_price->text());
    child->setText(3,ui->value->text());
    ui->lineEdit_price->clear();
    ui->value->clear();


    current_company->addChild(child);



    ui->lineEdit_price->clear();
}


void MainWindow::on_lineEdit_company_returnPressed()
{
    this->rootnamecompany = new QTreeWidgetItem(ui->treeWidget);
    rootnamecompany->setData(0,Qt::DisplayRole,ui->lineEdit_company->text());
    ui->treeWidget->addTopLevelItem(rootnamecompany);


    ui->lineEdit_company->clear();
}

////////////////////////Home Tasks
///
///
void MainWindow::on_Add_Task_btn_clicked()
{
     //ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());
    ui->New_Tasks_listWidget->addItem(item);
}


void MainWindow::on_Add_Task_lineEdit_returnPressed()
{
     ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());
}


void MainWindow::on_Delete_btn_clicked()
{
     QListWidgetItem *item = ui->New_Tasks_listWidget->currentItem();
     ui->New_Tasks_listWidget->removeItemWidget(item);
}

