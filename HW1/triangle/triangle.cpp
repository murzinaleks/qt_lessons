#include "triangle.h"
#include "ui_triangle.h"
#include <qmath.h>

triangle::triangle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::triangle)
{
    ui->setupUi(this);
}

triangle::~triangle()
{
    delete ui;
}

void triangle::on_button_calculate_clicked()
{
    double a = 0, b = 0, y = 0;
    double c = 0;

    a = ui->lineEdit_a->text().toDouble();
    b = ui->lineEdit_b->text().toDouble();
    y = ui->lineEdit_y->text().toDouble();

    if (ui->radioButton_rad->isChecked())
    {
        c = qSqrt(qPow(a, 2) + qPow(b, 2) - 2 * a * b * qCos(y));

        QString str = QString::number(double(c));

        ui->label_result->setText("cos(" + QString::number(y) +") = " + QString::number(qCos(y))+"\nсторона c = " + str);

    }
    else if (ui->radioButton_grad->isChecked())
    {
        double cos_y_gr = qCos(qDegreesToRadians(y));
        c = qSqrt(a*a + b*b - 2 * a * b * cos_y_gr);

        QString str = QString::number(c);

        ui->label_result->setText("cos(" + QString::number(y) +") = " + QString::number(cos_y_gr) + "\nсторона c = " + str);
    }
}
