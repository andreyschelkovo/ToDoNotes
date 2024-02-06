#ifndef FORM_FOR_DELETED_NOTES_H
#define FORM_FOR_DELETED_NOTES_H

#include <QWidget>

namespace Ui {
class Form_for_deleted_notes;
}

class Form_for_deleted_notes : public QWidget
{
    Q_OBJECT

public:
    explicit Form_for_deleted_notes(QWidget *parent = nullptr);
    ~Form_for_deleted_notes();

private:
    Ui::Form_for_deleted_notes *ui;
signals:
    void call_delete_notes_form();
private slots:
    void on_Deleted_form_save_btn_clicked();
};

#endif // FORM_FOR_DELETED_NOTES_H
