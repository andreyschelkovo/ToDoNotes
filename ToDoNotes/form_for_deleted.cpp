#include "form_for_deleted.h"
#include "ui_form_for_deleted.h"

Form_for_deleted::Form_for_deleted(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_for_deleted)
{
    ui->setupUi(this);
}

Form_for_deleted::~Form_for_deleted()
{
    delete ui;
}
