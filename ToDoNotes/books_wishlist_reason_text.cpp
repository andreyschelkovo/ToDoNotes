#include "books_wishlist_reason_text.h"
#include "ui_books_wishlist_reason_text.h"

Books_wishlist_reason_text::Books_wishlist_reason_text(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Books_wishlist_reason_text)
{
    ui->setupUi(this);
}

Books_wishlist_reason_text::~Books_wishlist_reason_text()
{
    delete ui;
}

void Books_wishlist_reason_text::on_pushButton_books_save_reason_description_clicked()
{
    emit signal_for_books_reason_description(ui->textEdit_books_desription_reason->document()->toPlainText());
    ui->textEdit_books_desription_reason->clear();
    this->close();
}

