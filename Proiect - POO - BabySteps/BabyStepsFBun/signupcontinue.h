#ifndef SIGNUPCONTINUE_H
#define SIGNUPCONTINUE_H

#include <QWidget>

namespace Ui {
class SignUpContinue;
}

class SignUpContinue : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpContinue(QWidget *parent = nullptr);
    ~SignUpContinue();

private slots:
    void on_pushButton_clicked();

    void on_Register_2_clicked();

private:
    Ui::SignUpContinue *ui;
};

#endif // SIGNUPCONTINUE_H
