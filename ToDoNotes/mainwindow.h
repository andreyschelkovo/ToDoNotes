#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTreeWidgetItem>
#include <QDate>
#include <QSpinBox>
#include <QListWidget>
#include <deleted_description_form.h>
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

    void on_Add_Task_lineEdit_returnPressed();

    void on_Delete_btn_clicked();

    void on_Done_btn_clicked();

    void on_pushButton_Repeat_clicked();

    void on_pushButton_books_addnewbook_clicked();

private:
    Ui::MainWindow *ui;
    QTreeWidgetItem *rootnamecompany;
    QDate Date;
    Deleted_description_form *deldescrform;

public slots:

    void slot_for_copy_del_note(QString msg);




};
#endif // MAINWINDOW_H
