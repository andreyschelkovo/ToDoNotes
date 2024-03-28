#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deldescrform = new Deleted_description_form();
    booksreasontext = new Books_wishlist_reason_text();
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
    ui->New_Tasks_listWidget->setToolTip(tr("All unfulfilled tasks with added date and deadlines"));
    ui->Done_Tasks_listWidget->setToolTip(tr("All completed tasks with completed date of completion "));
    ui->Deleted_Tasks_listWidget->setToolTip(tr("All deleted tasks with description why it was deleted"));
    ui->tableWidget_new_tasks->setToolTip(tr("All unfulfilled tasks with added date and deadlines"));
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


//////////////////////////////Secirities
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
     //ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());

    //эти 3 строки пример того как можно создать экземпляр Qlistwidget и потом использовать его как аргумент функции addItem
    //проблема в том что в таком исполнении у меня не олучилось просто добавить некоторые записи в строку в виде текста в кавычках, хотя в returnpressed это работает
   // QListWidgetItem *item = new QListWidgetItem();
   // item->setText(Date.toString("dd.MM.yyyy") + " " + ": " + ui->Add_Task_lineEdit->text());
   // ui->New_Tasks_listWidget->addItem(item );

    ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->lineEdit_Add_Task->text() + " : " + ui->spinBox_deadline->text());



    ui->tableWidget_new_tasks->insertRow(0);
    QTableWidgetItem *dateitem = new QTableWidgetItem(Date.toString("dd.MM.yyyy"));
    QTableWidgetItem *taskitem = new QTableWidgetItem(ui->lineEdit_Add_Task->text());
    QTableWidgetItem *deadlineitem = new QTableWidgetItem (ui->spinBox_deadline->text());
    ui->tableWidget_new_tasks->setItem(0,0,dateitem);
    ui->tableWidget_new_tasks->setItem(0,1,taskitem);
    ui->tableWidget_new_tasks->setItem(0,2,deadlineitem);

    ui->lineEdit_Add_Task->clear();
    ui->spinBox_deadline->clear();
}


void MainWindow::on_Add_Task_lineEdit_returnPressed()
{
    ui->New_Tasks_listWidget->addItem(Date.toString("dd.MM.yyyy") + " " + ": " + ui->lineEdit_Add_Task->text() + " : " + ui->spinBox_deadline->text());
     ui->lineEdit_Add_Task->clear();
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

