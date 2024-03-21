#include "warning_window_for_doubletype_books_format.h"
#include "ui_warning_window_for_doubletype_books_format.h"

warning_window_for_doubletype_books_format::warning_window_for_doubletype_books_format(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warning_window_for_doubletype_books_format)
{
    ui->setupUi(this);
}

warning_window_for_doubletype_books_format::~warning_window_for_doubletype_books_format()
{
    delete ui;
}
