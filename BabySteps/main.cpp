#include "BabySteps.h"
#include <QtWidgets/QApplication>
#include <QGradient>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BabySteps w;

    w.setWindowStyle();


    return a.exec();
}
