#ifndef MYQTABWIDGET_H
#define MYQTABWIDGET_H

#include <QWidget>

namespace Ui {
class MyQTabWidget;
}

class MyQTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyQTabWidget(QWidget *parent = nullptr);
    ~MyQTabWidget();

signals:
    void signal_from_myQTab(int index);

private slots:
    void
private:
    Ui::MyQTabWidget *ui;
};

#endif // MYQTABWIDGET_H
