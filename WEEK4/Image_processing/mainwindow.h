#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QImage image;
    QImage grayImg;
    QImage contrastImg;
    QImage thresholdImg;
    QImage pseudoImg;

    bool grayReady = false;


    bool contrastReady = false;


    bool thresoldready = false;

    bool pesudoready = false;

    int lastContrastValue = -1;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
