#include "myqtabwidget.h"
#include "ui_myqtabwidget.h"

MyQTabWidget::MyQTabWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyQTabWidget)
{
    ui->setupUi(this);
}

MyQTabWidget::~MyQTabWidget()
{
    delete ui;
}
