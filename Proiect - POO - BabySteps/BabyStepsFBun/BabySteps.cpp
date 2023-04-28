#include "BabySteps.h"
#include<QTimer>
#include<QDateTime>



BabySteps::BabySteps(QWidget *parent)
    : QMainWindow(parent)
{


    ui.setupUi(this);
    setWindowStyle();
    displayTime();

}

BabySteps::~BabySteps()
{}

void BabySteps::setWindowStyle()
{
    QIcon icon("C:/Users/denis/Desktop/BabyStepsFBun/icon.png");
    setWindowIcon(icon);

    QPixmap image("C:/Users/denis/Desktop/BabyStepsFBun/man.png");
    QPixmap pix = image.scaled(ui.icon->size(), Qt::KeepAspectRatio);
    ui.icon->setPixmap(pix);

    QLinearGradient gradient(0, 0, width(), height() / 2);
    gradient.setColorAt(0, QColor(0, 255, 0));
    gradient.setColorAt(1, QColor(255, 255, 255));

    QPalette pal = palette();
    pal.setBrush(QPalette::Window, QBrush(gradient));
    setAutoFillBackground(true);
    setPalette(pal);
    show();
}

void BabySteps::displayTime()
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}

void BabySteps::showTime()
{
    QTime oraActuala = QTime::currentTime();
    QString textOraActuala = oraActuala.toString("hh:mm:ss");
    ui.clock->setText(textOraActuala);
}

void BabySteps::on_login_clicked()
{
    SignUp ss;
    QString username=ui.username->text();
    QString passwordd=ui.password->text();

    bool T_or_F=ss.VerifyLogin(username,passwordd);
    if(T_or_F==true)
      {  QMessageBox::information(this,"Login Success","Login cool!");
        this->hide();
        MainWindow2 *w2=new MainWindow2();
        w2->show();
       }
    else
        QMessageBox::warning(this,"Failed","Login failed!");
}


void BabySteps::on_login_2_clicked()
{

        this->hide();
        SignUpContinue *sUc=new SignUpContinue();
        sUc->show();
}

