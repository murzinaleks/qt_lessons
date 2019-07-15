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

private:
    Ui::triangle *ui;
};

#endif // TRIANGLE_H
