#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1️⃣ QListWidget data
    ui->listWidget->addItems({"C++", "Qt", "Linux"});

    // 2️⃣ QTableWidget data
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Name"});

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("1"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("Ashish"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("2"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("Rahul"));

    // 3️⃣ QTreeWidget data
    ui->treeWidget->setHeaderLabel("Skills");

    QTreeWidgetItem *parentItem =
        new QTreeWidgetItem(ui->treeWidget, {"Programming"});

    new QTreeWidgetItem(parentItem, {"C++"});
    new QTreeWidgetItem(parentItem, {"Qt"});
    new QTreeWidgetItem(parentItem, {"Python"});
}

MainWindow::~MainWindow()
{
    delete ui;
}
