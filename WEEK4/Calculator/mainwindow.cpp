#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include<QLineEdit>
#include<QString>
#include<stack>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[this](){
        ui->lineEdit->setText(ui->lineEdit->text()+"1");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_digit1_clicked()
// {
//     ui->lineEdit->setText(ui->lineEdit->text()+"1");
// }


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}


void MainWindow::on_pushButton_10_clicked()
{
    currentOp="+";
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
}


int precedence(QChar op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, QChar op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return b == 0 ? 0 : a / b;
    return 0;
}


void MainWindow::on_pushButton_15_clicked() // "="
{
    QString expr = ui->lineEdit->text();
    bool isop=false;
    for (int i = 0; i < expr.length(); i++) {
        QChar ch1 = expr[i];


        if(!ch1.isDigit() && i!=0 && expr[i-1].isDigit())
        {
            isop=true;
        }


    }

    if(!isop)
    {
        exit(0);
    }
    std::stack<double> values;
    std::stack<QChar> ops;

    QString currentNumber;

    for (int i = 0; i < expr.length(); i++) {
        QChar ch = expr[i];


        if (ch.isDigit() || ch == '.') {
            currentNumber += ch;
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {


            values.push(currentNumber.toDouble());
            currentNumber.clear();


            while (!ops.empty() &&
                   precedence(ops.top()) >= precedence(ch)) {

                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                QChar op = ops.top(); ops.pop();

                values.push(applyOp(a, b, op));
            }

            ops.push(ch);
        }
    }


    if (!currentNumber.isEmpty())
        values.push(currentNumber.toDouble());


    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        QChar op = ops.top(); ops.pop();

        values.push(applyOp(a, b, op));
    }


    ui->lineEdit->setText(QString::number(values.top()));
}



void MainWindow::on_pushButton_11_clicked()
{
    currentOp="-";
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
}


void MainWindow::on_pushButton_12_clicked()
{
    currentOp="*";
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
}


void MainWindow::on_pushButton_14_clicked()
{
    currentOp="/";
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+".");
}

