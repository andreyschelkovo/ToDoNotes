#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTreeWidgetItem>
#include <QDate>
#include <QSpinBox>
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

private:
    Ui::MainWindow *ui;
    QTreeWidgetItem *rootnamecompany;
    QDate Date;

};
#endif // MAINWINDOW_H
