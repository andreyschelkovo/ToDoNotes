#ifndef FORM_FOR_DELETED_H
#define FORM_FOR_DELETED_H

#include <QWidget>

namespace Ui {
class Form_for_deleted;
}

class Form_for_deleted : public QWidget
{
    Q_OBJECT

public:
    explicit Form_for_deleted(QWidget *parent = nullptr);
    ~Form_for_deleted();

private:
    Ui::Form_for_deleted *ui;
};

#endif // FORM_FOR_DELETED_H
