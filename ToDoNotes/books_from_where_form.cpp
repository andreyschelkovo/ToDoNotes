#include "books_from_where_form.h"
#include "ui_books_from_where_form.h"

Books_From_where_Form::Books_From_where_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Books_From_where_Form)
{
    ui->setupUi(this);
}

Books_From_where_Form::~Books_From_where_Form()
{
    delete ui;
}

void Books_From_where_Form::on_pushButton_books_fr_wh_form_clicked()
{
    emit signal_from_books_fr_wh_form(ui->textEdit_books_fr_wh_form->document()->toPlainText());
    ui->textEdit_books_fr_wh_form->clear();
    this->close();
}

