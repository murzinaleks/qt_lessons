#include "lesson_4.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("://QtLanguage_" + QLocale::system().name()); //ru_Ru
    a.installTranslator(&translator);
    Lesson_4 w;
    w.show();

    return a.exec();
}
