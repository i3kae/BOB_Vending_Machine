#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(QString::number(money));
    //msg.information(nullptr,"Title","Text");
    if(money >= 100)
    {
        ui->pbCoffee->setEnabled(true);
        ui->pbCoffee->repaint();
    }
    if(money >= 150)
    {
        ui->pbTea->setEnabled(true);
        ui->pbTea->repaint();
    }
    if(money >= 200)
    {
        ui->pbGongcha->setEnabled(true);
        ui->pbGongcha->repaint();
    }
}
void Widget::on_pb10_clicked()
{
    ChangeMoney(10);
}

void Widget::on_pb50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_pb100_clicked()
{
    ChangeMoney(100);
}

void Widget::on_pb500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    if(money-100<0)
    {
        ui->pbCoffee->setEnabled(false);
        ui->pbCoffee->repaint();
    }
    else
        ChangeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    if(money-150<0)
    {
        ui->pbTea->setEnabled(false);
        ui->pbTea->repaint();
    }
    else
        ChangeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
    if(money-200<0)
    {
        ui->pbGongcha->setEnabled(false);
        ui->pbGongcha->repaint();
    }
    else
        ChangeMoney(-200);
}


void Widget::on_pbReturnMoney_clicked()
{
    QMessageBox msg;
    int tmp = money;
    int getsu[6]={0,};


    while(tmp)
    {
        if(tmp>=500)
        {
            getsu[0]++;
            tmp-=500;
        }
        else if (tmp>=100)
        {
            getsu[1]++;
            tmp-=100;
        }
        else if (tmp>=50)
        {
            getsu[2]++;
            tmp-=50;
        }
        else
        {
            getsu[3]++;
            tmp-=10;
        }
    }
    money=0;
    ui->lcdNumber->display("0");
    QString ReturnMoney = QString("500 : %1\n100 : %2\n50 : %3\n10 : %4").arg(getsu[0]).arg(getsu[1]).arg(getsu[2]).arg(getsu[3]);
    msg.information(nullptr,"Return Money",ReturnMoney);
}
