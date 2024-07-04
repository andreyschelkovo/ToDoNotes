#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QtWidgets>
#include <QTreeWidgetItem>
#include <QDate>
#include <QSpinBox>
#include <QListWidget>
#include <deleted_description_form.h>
#include <books_wishlist_reason_text.h>
#include <QMessageBox>
#include <books_from_where_form.h>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



    void on_Add_New_btn_clicked();



    void on_Save_Price_btn_clicked();

    void on_lineEdit_company_returnPressed();

    void on_Add_Task_btn_clicked();

    void on_Delete_btn_clicked();

    void on_Done_btn_clicked();

    void on_pushButton_Repeat_clicked();

    void on_pushButton_books_addnewbook_clicked();

    void on_pushButton_books_updateReadTime_clicked();

    void on_lineEdit_Add_Task_returnPressed();

    void on_pushButton_home_tasks_new_tasks_refresh_clicked();

    bool query_check_3cols(QString &table_name,QString &column1, QString &column2, QString &column3);


private:
    Ui::MainWindow *ui;
    QTreeWidgetItem *rootnamecompany;
    QDate Date;
    Deleted_description_form *deldescrform;
    Books_wishlist_reason_text *booksreasontext;
    Books_From_where_Form *books_fr_wh_form;


public slots:

    void slot_for_copy_del_note(QString msg);
    void slot_for_books_reason_description(QString msg);
    void slot_for_books_from_where_form(QString msg);




};
#endif // MAINWINDOW_H
