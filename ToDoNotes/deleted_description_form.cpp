#include "deleted_description_form.h"
#include "ui_deleted_description_form.h"

Deleted_description_form::Deleted_description_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deleted_description_form)
{
    ui->setupUi(this);
}

Deleted_description_form::~Deleted_description_form()
{
    delete ui;
}
