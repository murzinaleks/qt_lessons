#include "triangle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    triangle w;
    w.show();

    return a.exec();
}
