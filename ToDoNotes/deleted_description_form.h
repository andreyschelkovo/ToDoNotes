#ifndef DELETED_DESCRIPTION_FORM_H
#define DELETED_DESCRIPTION_FORM_H

#include <QWidget>

namespace Ui {
class Deleted_description_form;
}

class Deleted_description_form : public QWidget
{
    Q_OBJECT

public:
    explicit Deleted_description_form(QWidget *parent = nullptr);
    ~Deleted_description_form();

signals:
    void signal_for_del_note(QString msg);

private slots:
    void on_pushButton_save_del_description_clicked();

private:
    Ui::Deleted_description_form *ui;
};

#endif // DELETED_DESCRIPTION_FORM_H
