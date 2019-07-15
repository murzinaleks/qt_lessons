#include "quadratic.h"
#include "ui_quadratic.h"
#include <qmath.h>

quadratic::quadratic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::quadratic)
{
    ui->setupUi(this);
}

quadratic::~quadratic()
{
    delete ui;
}

void quadratic::on_button_calculate_clicked()
{
    float a = ui->lineEdit_a->text().toFloat();
    float b = ui->lineEdit_b->text().toFloat();
    float c = ui->lineEdit_c->text().toFloat();

    double d, x1, x2;

    d = b*b - 4*a*c;

    if (d > 0)
    {
        x1 = (-b + qSqrt(d)) / (2 * a);
        x2 = (-b - qSqrt(d)) / (2 * a);

        QString str = QString::number(x1);
        QString str2 = QString::number(x2);

        ui->label_calculated_result->setText("x1 = " + str + "\n" + "x2 = " + str2);
    }
    else if (d == 0)
    {
        x1 = -b / (2 * a);
        QString str = QString::number(x1);
        ui->label_calculated_result->setText("x1 = " + str);

    }
    else if (d < 0)
    {
        ui->label_calculated_result->setText("Нет решений");

    }

}
