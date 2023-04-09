#include "BabySteps.h"
#include<QTimer>
#include<QDateTime>



BabySteps::BabySteps(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QPixmap image("C:/Users/Denis/Desktop/Proiect - POO/BabySteps/BabySteps/man.png");
    QPixmap pix = image.scaled(ui.icon->size(), Qt::KeepAspectRatio);
    ui.icon->setPixmap(pix);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();

}

BabySteps::~BabySteps()
{}

void BabySteps::setWindowStyle()
{
    QIcon icon("C:/Users/Denis/Desktop/Proiect - POO/icon.png");
    setWindowIcon(icon);

    QLinearGradient gradient(0, 0, width(), height() / 2);
    gradient.setColorAt(0, QColor(0, 255, 0));
    gradient.setColorAt(1, QColor(255, 255, 255));

    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(gradient));
    setAutoFillBackground(true);
    setPalette(pal);


    show();
}


void BabySteps::showTime()
{
    QTime oraActuala = QTime::currentTime();
    QString textOraActuala = oraActuala.toString("hh:mm:ss");
    ui.clock->setText(textOraActuala);

}
