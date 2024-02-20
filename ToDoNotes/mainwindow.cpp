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
    //securities
    ui->lineEdit_company->setToolTip(tr("Here you should write the company name if you want to buy some their securities"));
    ui->treeWidget->setToolTip(tr("Here you will see all company names and their every date+price+count of securities"));
    ui->lineEdit_price->setToolTip(tr("Here you shoul write a price of securuties which you want to buy. It will be saved"));
    ui->spinBox_count_of_securities->setToolTip(tr("Here you should choose count of securities with exactly price"));
    //Home Tasks
    ui->Add_Task_lineEdit->setToolTip(tr("Write your task"));
    ui->New_Tasks_listWidget->setToolTip(tr("All unfulfilled tasks with added date and deadlines"));
    ui->Done_Tasks_listWidget->setToolTip(tr("All completed tasks with completed date of completion "));
    ui->Deleted_Tasks_listWidget->setToolTip(tr("All deleted tasks with description why it was deleted"));


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
    //QString test("text");
    rootnamecompany->setData(0,Qt::DisplayRole,ui->lineEdit_company->text());
    rootnamecompany->setText(3,"0");
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
    child->setText(3,ui->spinBox_count_of_securities->text());
    ui->lineEdit_price->clear();
    ui->spinBox_count_of_securities->clear();


    current_company->addChild(child);



    ui->lineEdit_price->clear();
}


void MainWindow::on_lineEdit_company_returnPressed()
{
    this->rootnamecompany = new QTreeWidgetItem(ui->treeWidget);
    //QString test("text");
    rootnamecompany->setData(0,Qt::DisplayRole,ui->lineEdit_company->text());
    rootnamecompany->setText(3,"0");
    ui->treeWidget->addTopLevelItem(rootnamecompany);


    ui->lineEdit_company->clear();
}

////////////////////////Home Tasks
///
///
void MainWindow::on_Add_Task_btn_clicked()
{
     //ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());

    //эти 3 строки пример того как можно создать экземпляр Qlistwidget и потом использовать его как аргумент функции addItem
    //проблема в том что в таком исполнении у меня не олучилось просто добавить некоторые записи в строку в виде текста в кавычках, хотя в returnpressed это работает
   // QListWidgetItem *item = new QListWidgetItem();
   // item->setText(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());
   // ui->New_Tasks_listWidget->addItem(item );

    ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text() + " : " + ui->spinBox_deadline->text());
    ui->Add_Task_lineEdit->clear();


    ui->tableWidget_new_tasks->insertRow(0);
    QTableWidgetItem *dateitem = new QTableWidgetItem(Date.toString("dd.MM.yyyy"));
    QTableWidgetItem *taskitem = new QTableWidgetItem();
   // QTableWidgetItem *deadline = new QTableWidgetItem("jjjjjjjjjj");

    ui->tableWidget_new_tasks->setItem(0,0,dateitem);
    ui->tableWidget_new_tasks->setItem(0,1,taskitem);
}


void MainWindow::on_Add_Task_lineEdit_returnPressed()
{
    ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text() + " : " + ui->spinBox_deadline->text());
     ui->Add_Task_lineEdit->clear();
}


void MainWindow::on_Delete_btn_clicked()
{
     QListWidgetItem *item_created_to_show_on_deleted_list = new QListWidgetItem();
     QListWidgetItem *itemrow = ui->New_Tasks_listWidget->takeItem(ui->New_Tasks_listWidget->currentRow());
     Date = Date.currentDate();
     item_created_to_show_on_deleted_list->setText("Deleted " + Date.toString("dd.MM.yyyy") + " " + "Added: " + itemrow->text());
     ui->Deleted_Tasks_listWidget->addItem(item_created_to_show_on_deleted_list);

     delete itemrow;

     deldescrform->show();

}


void MainWindow::on_Done_btn_clicked()
     {
     QListWidgetItem *itemfrom = ui->New_Tasks_listWidget->item(ui->New_Tasks_listWidget->currentRow());
     QListWidgetItem *itemto = new QListWidgetItem();
     Date = Date.currentDate();
     itemto->setText(Date.toString("dd.MM.yyyy") + " " + ": " + itemfrom->text());
     ui->Done_Tasks_listWidget->addItem(itemto);
     itemto->setBackground(Qt::green);
     delete itemfrom;



     }

void MainWindow::slot_for_copy_del_note(QString msg)
     {
     ui->textEdit_Deleted_example->setText(msg);


     }


void MainWindow::on_pushButton_Repeat_clicked()
{
     QListWidgetItem *itemfrom = ui->Deleted_Tasks_listWidget->item(ui->Deleted_Tasks_listWidget->currentRow());
     QListWidgetItem *itemto = new QListWidgetItem();
     Date = Date.currentDate();
     itemto->setText(Date.toString("dd.MM.yyyy") + " " + ": " + itemfrom->text());
     ui->New_Tasks_listWidget->addItem(itemto);
    //тут я нормально переношу текст, но текст совершенно не верный, нужно редактировать листвиджеты добавляя столбцы под дату и текст, см конспект

     delete itemfrom;
}

