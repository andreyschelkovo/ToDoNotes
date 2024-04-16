#ifndef BOOKS_FROM_WHERE_FORM_H
#define BOOKS_FROM_WHERE_FORM_H

#include <QWidget>

namespace Ui {
class Books_From_where_Form;
}

class Books_From_where_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Books_From_where_Form(QWidget *parent = nullptr);
    ~Books_From_where_Form();
signals:
    void signal_from_books_fr_wh_form(QString msg);

private slots:
    void on_pushButton_books_fr_wh_form_clicked();

private:
    Ui::Books_From_where_Form *ui;
};

#endif // BOOKS_FROM_WHERE_FORM_H
