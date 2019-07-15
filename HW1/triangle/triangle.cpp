#include "triangle.h"
#include "ui_triangle.h"

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
