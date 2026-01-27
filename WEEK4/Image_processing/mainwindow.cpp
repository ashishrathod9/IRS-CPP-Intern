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
    if (image.isNull()) return;

    grayImg = QImage(image.size(), QImage::Format_RGB32);

    int totalPixels = image.width() * image.height();
    int processedPixels = 0;

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {

            QColor c = image.pixelColor(x, y);
            int g = (c.red() + c.green() + c.blue()) / 3;
            grayImg.setPixelColor(x, y, QColor(g, g, g));

            processedPixels++;

            if (x == image.width() - 1) {
                int progress = (processedPixels * 100) / totalPixels;
                ui->progressBar->setValue(progress);
            }
        }
    }

    ui->progressBar->setValue(100);
    ui->label->setPixmap(QPixmap::fromImage(grayImg));
}




void MainWindow::on_pushButton_3_clicked()
{
    if (image.isNull())
        return;


    int spinValue = ui->spinBoxContrast->value();
    float factor = spinValue ;


    contrastImg = QImage(image.size(), QImage::Format_RGB32);

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            QColor c = image.pixelColor(x, y);

            int r = qBound(0, int((c.red()   - 128) * factor + 128), 255);
            int g = qBound(0, int((c.green() - 128) * factor + 128), 255);
            int b = qBound(0, int((c.blue()  - 128) * factor + 128), 255);

            contrastImg.setPixelColor(x, y, QColor(r, g, b));
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(contrastImg));
}


void MainWindow::on_pushButton_4_clicked()
{
    int threshold = 128;

    if (!thresoldready) {
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

    thresoldready=true;

    }

    ui->label->setPixmap(QPixmap::fromImage(thresholdImg));
}


void MainWindow::on_pushButton_5_clicked()
{
    if(!pesudoready){
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

    pesudoready = true;

    }

    ui->label->setPixmap(QPixmap::fromImage(pseudoImg));
}



