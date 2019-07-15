#include "quadratic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    quadratic w;
    w.show();

    return a.exec();
}
