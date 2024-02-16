#include "deleted_description_form.h"
#include "ui_deleted_description_form.h"

Deleted_description_form::Deleted_description_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deleted_description_form)
{
    ui->setupUi(this);
    ui->label_instead_icon->setToolTip(tr("Delete reason Description"));
}

Deleted_description_form::~Deleted_description_form()
{
    delete ui;
}

void Deleted_description_form::on_pushButton_save_del_description_clicked()
{
    emit signal_for_del_note(ui->textEdit_Deleted_description->document()->toPlainText());
    this->close();

}

