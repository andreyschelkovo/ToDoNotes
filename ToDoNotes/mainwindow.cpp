#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deldescrform = new Deleted_description_form();
    connect(deldescrform,&Deleted_description_form::signal_for_del_note,this,&MainWindow::slot_for_copy_del_note);
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
    ui->Add_Task_lineEdit->clear();
}


void MainWindow::on_Add_Task_lineEdit_returnPressed()
{
     ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());
     ui->Add_Task_lineEdit->clear();
}


void MainWindow::on_Delete_btn_clicked()
{
     QListWidgetItem *item_created_to_show_on_deleted_list = new QListWidgetItem();
     QListWidgetItem *itemrow = ui->New_Tasks_listWidget->takeItem(ui->New_Tasks_listWidget->currentRow());
     item_created_to_show_on_deleted_list->setText(Date.toString("dd.MM.yyyy") + " " + ": " + itemrow->text());
     ui->Deleted_Tasks_listWidget->addItem(item_created_to_show_on_deleted_list);

     delete itemrow;

     deldescrform->show();

}


void MainWindow::on_Done_btn_clicked()
     {
     QListWidgetItem *itemfrom = ui->New_Tasks_listWidget->item(ui->New_Tasks_listWidget->currentRow());
     QListWidgetItem *itemto = new QListWidgetItem();
     itemto->setText(Date.toString("dd.MM.yyyy") + " " + ": " + itemfrom->text());
     ui->Done_Tasks_listWidget->addItem(itemto);
     itemto->setBackground(Qt::green);
     delete itemfrom;



     }

void MainWindow::slot_for_copy_del_note(QString msg)
     {
     ui->textEdit_Deleted_example->setText(msg);


     }

