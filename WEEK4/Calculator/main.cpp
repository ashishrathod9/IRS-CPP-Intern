#include "mainwindow.h"

#include <QApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    for (int i = 0; i < argc; i++) {
        qDebug() << argv[i];
    }
    MainWindow w;
    w.show();
    return a.exec();
}
