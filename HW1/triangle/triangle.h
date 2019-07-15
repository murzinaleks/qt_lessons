#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QMainWindow>

namespace Ui {
class triangle;
}

class triangle : public QMainWindow
{
    Q_OBJECT

public:
    explicit triangle(QWidget *parent = nullptr);
    ~triangle();

private slots:

    void on_button_calculate_clicked();

private:
    Ui::triangle *ui;
};

#endif // TRIANGLE_H
