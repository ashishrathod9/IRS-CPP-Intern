#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBoxOS->addItems({"Linux", "Windows", "Mac"});
    ui->spinBoxAge->setRange(1, 100);
    ui->sliderLevel->setRange(0, 100);

    ui->radioMale->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSubmit_clicked()
{
    QString name = ui->lineEditName->text();
    int age = ui->spinBoxAge->value();
    QString os = ui->comboBoxOS->currentText();
    QString gender = ui->radioMale->isChecked() ? "Male" : "Female";
    QDate dob = ui->dateEditDOB->date();
    bool agree = ui->checkBoxAgree->isChecked();
    int level = ui->sliderLevel->value();

    if (name.isEmpty() || !agree)
        return;



    QString output =
        "Name: " + name +
        "\nAge: " + QString::number(age) +
        "\nOS: " + os +
        "\nGender: " + gender +
        "\nDOB: " + dob.toString("dd-MM-yyyy") +
        "\nLevel: " + QString::number(level);

    ui->labelOutput->setText(output);
    ui->listWidgetLog->addItem(name + " submitted data");
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEditName->clear();
    ui->spinBoxAge->setValue(1);
    ui->comboBoxOS->setCurrentIndex(0);
    ui->radioMale->setChecked(true);
    ui->checkBoxAgree->setChecked(false);
    ui->sliderLevel->setValue(0);

    ui->labelOutput->clear();
}
