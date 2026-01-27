/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditName;
    QSpinBox *spinBoxAge;
    QComboBox *comboBoxOS;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioMale;
    QRadioButton *radioFemale;
    QDateEdit *dateEditDOB;
    QCheckBox *checkBoxAgree;
    QSlider *sliderLevel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSubmit;
    QPushButton *pushButtonClear;
    QLabel *labelOutput;
    QListWidget *listWidgetLog;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QTableView *tableView;
    QListView *listView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1059, 797);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 66, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 70, 66, 18));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 100, 66, 18));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 140, 66, 18));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 168, 66, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 220, 66, 18));
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(130, 30, 113, 26));
        spinBoxAge = new QSpinBox(centralwidget);
        spinBoxAge->setObjectName(QString::fromUtf8("spinBoxAge"));
        spinBoxAge->setGeometry(QRect(130, 60, 44, 27));
        comboBoxOS = new QComboBox(centralwidget);
        comboBoxOS->setObjectName(QString::fromUtf8("comboBoxOS"));
        comboBoxOS->setGeometry(QRect(130, 100, 71, 26));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 130, 230, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioMale = new QRadioButton(horizontalLayoutWidget);
        radioMale->setObjectName(QString::fromUtf8("radioMale"));

        horizontalLayout->addWidget(radioMale);

        radioFemale = new QRadioButton(horizontalLayoutWidget);
        radioFemale->setObjectName(QString::fromUtf8("radioFemale"));

        horizontalLayout->addWidget(radioFemale);

        dateEditDOB = new QDateEdit(centralwidget);
        dateEditDOB->setObjectName(QString::fromUtf8("dateEditDOB"));
        dateEditDOB->setGeometry(QRect(120, 170, 110, 27));
        checkBoxAgree = new QCheckBox(centralwidget);
        checkBoxAgree->setObjectName(QString::fromUtf8("checkBoxAgree"));
        checkBoxAgree->setGeometry(QRect(120, 220, 92, 24));
        sliderLevel = new QSlider(centralwidget);
        sliderLevel->setObjectName(QString::fromUtf8("sliderLevel"));
        sliderLevel->setGeometry(QRect(50, 270, 160, 16));
        sliderLevel->setOrientation(Qt::Horizontal);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(50, 300, 271, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonSubmit = new QPushButton(horizontalLayoutWidget_2);
        pushButtonSubmit->setObjectName(QString::fromUtf8("pushButtonSubmit"));

        horizontalLayout_2->addWidget(pushButtonSubmit);

        pushButtonClear = new QPushButton(horizontalLayoutWidget_2);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        horizontalLayout_2->addWidget(pushButtonClear);

        labelOutput = new QLabel(centralwidget);
        labelOutput->setObjectName(QString::fromUtf8("labelOutput"));
        labelOutput->setGeometry(QRect(50, 360, 251, 181));
        listWidgetLog = new QListWidget(centralwidget);
        listWidgetLog->setObjectName(QString::fromUtf8("listWidgetLog"));
        listWidgetLog->setGeometry(QRect(50, 551, 256, 41));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 30, 371, 561));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(verticalLayoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_2->addWidget(treeView);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        listView = new QListView(verticalLayoutWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1059, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Name      :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Age          :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "OS            :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Gender   :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "DOB        :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Agree     :", nullptr));
        radioMale->setText(QCoreApplication::translate("MainWindow", "Male", nullptr));
        radioFemale->setText(QCoreApplication::translate("MainWindow", "Female", nullptr));
        checkBoxAgree->setText(QCoreApplication::translate("MainWindow", "Agree", nullptr));
        pushButtonSubmit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        labelOutput->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
