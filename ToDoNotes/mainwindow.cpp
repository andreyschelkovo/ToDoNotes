#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deldescrform = new Deleted_description_form();
    booksreasontext = new Books_wishlist_reason_text();
    books_fr_wh_form = new Books_From_where_Form();
    connect(books_fr_wh_form,&Books_From_where_Form::signal_from_books_fr_wh_form,this,&MainWindow::slot_for_books_from_where_form);
    connect(deldescrform,&Deleted_description_form::signal_for_del_note,this,&MainWindow::slot_for_copy_del_note);
    connect(booksreasontext,&Books_wishlist_reason_text::signal_for_books_reason_description,this,&MainWindow::slot_for_books_reason_description);

    Date = Date.currentDate();
    //securities
    ui->lineEdit_company->setToolTip(tr("Here you should write the company name if you want to buy some their securities"));
    ui->treeWidget->setToolTip(tr("Here you will see all company names and their every date+price+count of securities"));
    ui->lineEdit_price->setToolTip(tr("Here you shoul write a price of securuties which you want to buy. It will be saved"));
    ui->spinBox_count_of_securities->setToolTip(tr("Here you should choose count of securities with exactly price"));
    //Home Tasks
    ui->lineEdit_Add_Task->setToolTip(tr("Write your task"));

    ui->tableWidget_home_tasks_new_tasks->setToolTip(tr("All unfulfilled tasks with added date and deadlines"));
    //Books
    ui->tableWidget_books_finished_list->setToolTip(tr("Here you can see all books which you already read"));
    ui->tableWidget_books_wishlist->setToolTip(tr("Here you can see all books what you want to read"));
    ui->lineEdit_books_book_name->setToolTip(tr("Write the name of the book here"));
    ui->lineEdit_books_autors_name->setToolTip(tr("Write autor's name if you want"));
    ui->pushButton_books_addnewbook->setToolTip(tr("Press me to remember your choice"));
    ui->checkBox_books_audio->setToolTip(tr("Choose a type of book if you remember how you knew it"));
    ui->checkBox_books_text->setToolTip(tr("Choose a type of book if you remember how you knew it"));
    ui->radioButton_books_fiished->setToolTip(tr("Choose do you want to read this book or you already read it"));
    ui->radioButton_books_wishlist->setToolTip(tr("Choose do you want to read this book or you already read it"));

    ui->textEdit_example_of_reason->setToolTip(tr("This is just an example of work. This message should be send on the server or DB and it should connect with the particular book in "
                                                  "wish list"));
    ui->label_example_of_reason->setToolTip(tr("just label of that example"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//////////////////////////////Securities
///============================================================================================================================================
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

////////////////////////Home Tasks=====================================================================================================================
///
///
void MainWindow::on_Add_Task_btn_clicked()
{


    if ( ui->lineEdit_Add_Task->text().isEmpty()){
    QMessageBox::warning(this,tr("Empty Task Error"),tr("You have to write smth into the field and only then press button"));
    }
    else {
    ui->tableWidget_home_tasks_new_tasks->insertRow(0);
    QTableWidgetItem *dateitem = new QTableWidgetItem(Date.toString("dd.MM.yyyy"));
    QTableWidgetItem *taskitem = new QTableWidgetItem(ui->lineEdit_Add_Task->text());
    QTableWidgetItem *deadlineitem = new QTableWidgetItem (ui->spinBox_deadline->text());
    ui->tableWidget_home_tasks_new_tasks->setItem(0,0,dateitem);
    ui->tableWidget_home_tasks_new_tasks->setItem(0,1,taskitem);
    ui->tableWidget_home_tasks_new_tasks->setItem(0,2,deadlineitem);

    ui->lineEdit_Add_Task->clear();
    ui->spinBox_deadline->setValue(0);


    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS my_table ("
                  "id SERIAL PRIMARY KEY,"
                  "name VARCHAR(50) NOT NULL,"
                  "salary INTEGER NOT NULL)");
    }


}



void MainWindow::on_lineEdit_Add_Task_returnPressed()
{
    if ( ui->lineEdit_Add_Task->text().isEmpty()){
    QMessageBox::warning(this,tr("Empty Task Error"),tr("You have to write smth into the field and only then press button"));
    }
    else {
    ui->tableWidget_home_tasks_new_tasks->insertRow(0);
    QTableWidgetItem *dateitem = new QTableWidgetItem(Date.toString("dd.MM.yyyy"));
    QTableWidgetItem *taskitem = new QTableWidgetItem(ui->lineEdit_Add_Task->text());
    QTableWidgetItem *deadlineitem = new QTableWidgetItem (ui->spinBox_deadline->text());
    ui->tableWidget_home_tasks_new_tasks->setItem(0,0,dateitem);
    ui->tableWidget_home_tasks_new_tasks->setItem(0,1,taskitem);
    ui->tableWidget_home_tasks_new_tasks->setItem(0,2,deadlineitem);

    ui->lineEdit_Add_Task->clear();
    ui->spinBox_deadline->setValue(0);
    }
}




void MainWindow::on_Delete_btn_clicked()
{
    Date = Date.currentDate();
    ui->tableWidge_home_tasks_deleted_tasks->insertRow(0);
    int number_of_selected_row = ui->tableWidget_home_tasks_new_tasks->currentRow();
    int selected_row_column_count = ui->tableWidget_home_tasks_new_tasks->columnCount();
    QTableWidgetItem *delete_date = new QTableWidgetItem (Date.toString());

    ui->tableWidge_home_tasks_deleted_tasks->setItem(0,0,delete_date);
    for(int i = 1; i < selected_row_column_count; i++){
    QTableWidgetItem *transfer_item = ui->tableWidget_home_tasks_new_tasks->item(number_of_selected_row,i);
    ui->tableWidge_home_tasks_deleted_tasks->setItem(0,i,transfer_item->clone());
    ui->tableWidge_home_tasks_deleted_tasks->item(0,i)->setBackground(Qt::red);

    }
    ui->tableWidget_home_tasks_new_tasks->removeRow(number_of_selected_row);

    deldescrform->show();

}
void MainWindow::on_pushButton_Repeat_clicked()
{
    Date = Date.currentDate();
    int number_of_selected_row = ui->tableWidge_home_tasks_deleted_tasks->currentRow();
    QTableWidgetItem *repeate_date_item = new QTableWidgetItem(Date.toString("dd.MM.yyyy"));
    QTableWidgetItem *repeate_deadline_item = new QTableWidgetItem (ui->spinBox_Repeat->text());
    QTableWidgetItem *repeate_transfer_task = ui->tableWidge_home_tasks_deleted_tasks->item(number_of_selected_row,1);

    ui->tableWidget_home_tasks_new_tasks->insertRow(0);

    ui->tableWidget_home_tasks_new_tasks->setItem(0,0,repeate_date_item);
    ui->tableWidget_home_tasks_new_tasks->setItem(0,1,repeate_transfer_task->clone());
    ui->tableWidget_home_tasks_new_tasks->setItem(0,2,repeate_deadline_item);

    ui->tableWidge_home_tasks_deleted_tasks->removeRow(number_of_selected_row);
    ui->spinBox_Repeat->setValue(0);

}


void MainWindow::on_Done_btn_clicked()
     {
     Date = Date.currentDate();
     ui->tableWidget_home_tasks__done_tasks->insertRow(0);
     int number_of_selected_row = ui->tableWidget_home_tasks_new_tasks->currentRow();
     int selected_row_column_count = ui->tableWidget_home_tasks_new_tasks->columnCount();
     QTableWidgetItem *done_date = new QTableWidgetItem (Date.toString());

     ui->tableWidget_home_tasks__done_tasks->setItem(0,0,done_date);
     for(int i = 1; i < selected_row_column_count; i++){
         QTableWidgetItem *transfer_item = ui->tableWidget_home_tasks_new_tasks->item(number_of_selected_row,i);
         ui->tableWidget_home_tasks__done_tasks->setItem(0,i,transfer_item->clone());
         ui->tableWidget_home_tasks__done_tasks->item(0,i)->setBackground(Qt::green);
     }

    ui->tableWidget_home_tasks_new_tasks->removeRow(number_of_selected_row);
     //itemto->setBackground(Qt::green);

     }

void MainWindow::slot_for_copy_del_note(QString msg)
     {
     ui->textEdit_Deleted_example->setText(msg);


     }






/////////Books==================================================================================================================================================
void MainWindow::on_pushButton_books_addnewbook_clicked()
{
     if ((ui->checkBox_books_audio->isChecked()==true)&&(ui->checkBox_books_text->isChecked()==true)){
         QMessageBox::warning(this,tr("DoubleType Error"),tr("You have to choose only one type of the book, but probably you try to chooce both"));

     }
     else if ((ui->checkBox_books_audio->isChecked()==false)&&(ui->checkBox_books_text->isChecked()==false)&&
         (ui->radioButton_books_fiished->isChecked()==true)){
         QMessageBox::warning(this,tr("None Type Error"),tr("You have to choose at least one type of the book, but probably you chooce no one"));

     }
     else {
         if(ui->radioButton_books_wishlist->isChecked()==true){
             ui->tableWidget_books_wishlist->insertRow(0);
             QTableWidgetItem *bookname = new QTableWidgetItem(ui->lineEdit_books_book_name->text());
             QTableWidgetItem *autorname = new QTableWidgetItem(ui->lineEdit_books_autors_name->text());
             ui->tableWidget_books_wishlist->setItem(0,0,bookname);
             ui->tableWidget_books_wishlist->setItem(0,1,autorname);
             booksreasontext->show();
             books_fr_wh_form->show();


         }else if (ui->radioButton_books_fiished->isChecked()==true){
             ui->tableWidget_books_finished_list->insertRow(0);
             QTableWidgetItem *bookname = new QTableWidgetItem(ui->lineEdit_books_book_name->text());
             QTableWidgetItem *autorname = new QTableWidgetItem(ui->lineEdit_books_autors_name->text());
             QTableWidgetItem *dateitem = new QTableWidgetItem(Date.toString("dd.MM.yyyy"));
             ui->tableWidget_books_finished_list->setItem(0,0,bookname);
             ui->tableWidget_books_finished_list->setItem(0,1,autorname);
             ui->tableWidget_books_finished_list->setItem(0,3,dateitem);
         }
         if(ui->checkBox_books_audio->isChecked()==true){
             QTableWidgetItem *audiomark = new QTableWidgetItem("audio");
             ui->tableWidget_books_finished_list->setItem(0,2,audiomark);
         }else if(ui->checkBox_books_text->isChecked()==true){
             QTableWidgetItem *textmark = new QTableWidgetItem ("Text");
             ui->tableWidget_books_finished_list->setItem(0,2,textmark);
         }
     }///

}

void MainWindow::slot_for_books_reason_description(QString msg)
{
     ui->textEdit_example_of_reason->setText(msg);

     QTableWidgetItem *reason = new QTableWidgetItem(msg);
     ui->tableWidget_books_wishlist->setItem(0,2,reason);

}

void MainWindow::slot_for_books_from_where_form(QString msg)
{
     QTableWidgetItem *msg_from_where_form = new QTableWidgetItem(msg);
     ui->tableWidget_books_wishlist->setItem(0,3,msg_from_where_form->clone());
}


void MainWindow::on_pushButton_books_updateReadTime_clicked()
{
     int rowcountbooks = ui->tableWidget_books_finished_list->rowCount();

     if (rowcountbooks > 0){
         for(int i = 0; i < rowcountbooks; i++ ){
             QTableWidgetItem  *currentwidgetitem = ui->tableWidget_books_finished_list->item(i,4);//создаю итемс нужной для проверки ячейкой
             QDate start_read_Date =QDate::fromString( ui->tableWidget_books_finished_list->item(i,3)->text(),"dd.MM.yyyy");//дата нчала чтения
             QDate end_read_date = QDate::fromString((currentwidgetitem->text()),"dd.MM.yyyy");//дата окончания чтения
             if (currentwidgetitem != nullptr){//проверка на наличие даты окончания чтения, известна л она вообще
                 //вычисляем дату и суем в нужную ячейку
                 int count_read_days = start_read_Date.daysTo(end_read_date);//ф-я подсчёта дней между первой датой и второй
                 QTableWidgetItem *textmark2 = new QTableWidgetItem ();
                 textmark2->setData(Qt::DisplayRole,QVariant(count_read_days));//не до конца понимаю что значат аргументы
                 ui->tableWidget_books_finished_list->setItem(i,5,textmark2);//отобраю подсчёт

             }
             //delete currentwidgetitem;
         }

     }
     else {
        //варнинг окно про пустую таблицу
     }
}




