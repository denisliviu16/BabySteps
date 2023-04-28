#include "mainwindow.h"
#include "BabySteps.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BabySteps bb;
    bb.show();

    //MainWindow w;
    //w.show();
    return a.exec();
}
