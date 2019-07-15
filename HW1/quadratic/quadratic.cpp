#include "quadratic.h"
#include "ui_quadratic.h"

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
