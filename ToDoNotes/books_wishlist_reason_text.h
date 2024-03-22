#ifndef BOOKS_WISHLIST_REASON_TEXT_H
#define BOOKS_WISHLIST_REASON_TEXT_H

#include <QWidget>

namespace Ui {
class Books_wishlist_reason_text;
}

class Books_wishlist_reason_text : public QWidget
{
    Q_OBJECT

public:
    explicit Books_wishlist_reason_text(QWidget *parent = nullptr);
    ~Books_wishlist_reason_text();
signals:
    void signal_for_books_reason_description(QString msg);

private slots:
    void on_pushButton_books_save_reason_description_clicked();

private:
    Ui::Books_wishlist_reason_text *ui;
};

#endif // BOOKS_WISHLIST_REASON_TEXT_H
