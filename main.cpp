#include "launcher.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Launcher w;

    w.show();

    return a.exec();
}
