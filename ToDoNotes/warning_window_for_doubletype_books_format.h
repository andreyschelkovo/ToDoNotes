#ifndef WARNING_WINDOW_FOR_DOUBLETYPE_BOOKS_FORMAT_H
#define WARNING_WINDOW_FOR_DOUBLETYPE_BOOKS_FORMAT_H

#include <QWidget>

namespace Ui {
class warning_window_for_doubletype_books_format;
}

class warning_window_for_doubletype_books_format : public QWidget
{
    Q_OBJECT

public:
    explicit warning_window_for_doubletype_books_format(QWidget *parent = nullptr);
    ~warning_window_for_doubletype_books_format();

private:
    Ui::warning_window_for_doubletype_books_format *ui;
};

#endif // WARNING_WINDOW_FOR_DOUBLETYPE_BOOKS_FORMAT_H
