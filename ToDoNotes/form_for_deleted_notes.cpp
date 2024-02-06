#include "form_for_deleted_notes.h"
#include "ui_form_for_deleted_notes.h"

Form_for_deleted_notes::Form_for_deleted_notes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_for_deleted_notes)
{
    ui->setupUi(this);
}

Form_for_deleted_notes::~Form_for_deleted_notes()
{
    delete ui;
}
