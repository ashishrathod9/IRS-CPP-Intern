#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QImage>
#include<QString>
#include<QPixmap>
#include<QFileDialog>
#include<QColor>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,   &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_pushButton_5_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(
        this,
        "Open Image",
        "",
        "Images (*.png *.jpeg *.jpeg *.bmp)"
        );

    if (path.isEmpty())
        return;

    if (!image.load(path))
        return;

    // Prepare images
    grayImg = QImage(image.size(), QImage::Format_RGB32);
    contrastImg = QImage(image.size(), QImage::Format_RGB32);
    thresholdImg = QImage(image.size(), QImage::Format_RGB32);
    pseudoImg = QImage(image.size(), QImage::Format_RGB32);

    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::on_pushButton_2_clicked()
{
    QImage grayImg(image.size(), QImage::Format_RGB32);
    for (int y = 0; y < image.height(); y++)
    {
        for (int x = 0; x < image.width(); x++)
        {
            QColor c = image.pixelColor(x, y);

            int r = c.red();
            int g = c.green();
            int b = c.blue();
            qDebug() <<r<<g<<b;
            // -------- GRAYSCALE --------
            int gray = (r + g + b) / 3;
            grayImg.setPixelColor(x, y, QColor(gray, gray, gray));


        }
    }
    ui->label->setPixmap(QPixmap::fromImage(grayImg));
}


void MainWindow::on_pushButton_3_clicked()
{
    float factor = 1.2f;     // contrast factor
        // threshold value

    QImage contrastImg(image.size(), QImage::Format_RGB32);

    for (int y = 0; y < image.height(); y++)
    {
        for (int x = 0; x < image.width(); x++)
        {
            QColor c = image.pixelColor(x, y);

            int r = c.red();
            int g = c.green();
            int b = c.blue();

            // -------- GRAYSCALE --------
            int gray = (r + g + b) / 3;


            // -------- CONTRAST --------
            int newR = (r - 128) * factor + 128;
            int newG = (g - 128) * factor + 128;
            int newB = (b - 128) * factor + 128;

            newR = qBound(0, newR, 255);
            newG = qBound(0, newG, 255);
            newB = qBound(0, newB, 255);

            contrastImg.setPixelColor(x, y, QColor(newR, newG, newB));

        }
    }
    ui->label->setPixmap(QPixmap::fromImage(contrastImg));
}


void MainWindow::on_pushButton_4_clicked()
{
    int threshold = 128;

    for (int y = 0; y < image.height(); y++)
    {
        for (int x = 0; x < image.width(); x++)
        {
            QColor c = image.pixelColor(x, y);
            int gray = (c.red() + c.green() + c.blue()) / 3;

            if (gray > threshold)
                thresholdImg.setPixelColor(x, y, QColor(255,255,255));
            else
                thresholdImg.setPixelColor(x, y, QColor(0,0,0));
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(thresholdImg));
}


void MainWindow::on_pushButton_5_clicked()
{
    for (int y = 0; y < image.height(); y++)
    {
        for (int x = 0; x < image.width(); x++)
        {
            QColor c = image.pixelColor(x, y);
            int gray = (c.red() + c.green() + c.blue()) / 3;

            if (gray < 85)
                pseudoImg.setPixelColor(x, y, QColor(0,0,255));
            else if (gray < 170)
                pseudoImg.setPixelColor(x, y, QColor(0,255,0));
            else
                pseudoImg.setPixelColor(x, y, QColor(255,0,0));
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(pseudoImg));
}



