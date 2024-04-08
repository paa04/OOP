/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_exit;
    QWidget *centralwidget;
    QPushButton *transfer_btn;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QGridLayout *gridLayout_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_4;
    QDoubleSpinBox *scale_kx;
    QDoubleSpinBox *scale_ky;
    QDoubleSpinBox *scale_kz;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QGridLayout *gridLayout_6;
    QLabel *label_14;
    QLabel *label_5;
    QLabel *label_15;
    QDoubleSpinBox *rotate_x_val;
    QDoubleSpinBox *rotate_y_val;
    QDoubleSpinBox *rotat_z_val;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QGridLayout *gridLayout_7;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_6;
    QDoubleSpinBox *dx_val;
    QDoubleSpinBox *dy_val;
    QDoubleSpinBox *dz_val;
    QPushButton *rotate_btn;
    QPushButton *scale_btn;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *reset_btn;
    QPushButton *center_btn;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1353, 1005);
        MainWindow->setWindowOpacity(1.000000000000000);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        transfer_btn = new QPushButton(centralwidget);
        transfer_btn->setObjectName(QString::fromUtf8("transfer_btn"));
        transfer_btn->setGeometry(QRect(20, 170, 291, 51));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 460, 291, 128));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 1, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 2, 0, 1, 1);

        scale_kx = new QDoubleSpinBox(verticalLayoutWidget_3);
        scale_kx->setObjectName(QString::fromUtf8("scale_kx"));
        scale_kx->setMinimum(-999.000000000000000);
        scale_kx->setMaximum(999.000000000000000);
        scale_kx->setValue(1.000000000000000);

        gridLayout_5->addWidget(scale_kx, 0, 1, 1, 1);

        scale_ky = new QDoubleSpinBox(verticalLayoutWidget_3);
        scale_ky->setObjectName(QString::fromUtf8("scale_ky"));
        scale_ky->setMinimum(-999.000000000000000);
        scale_ky->setMaximum(999.000000000000000);
        scale_ky->setValue(1.000000000000000);

        gridLayout_5->addWidget(scale_ky, 1, 1, 1, 1);

        scale_kz = new QDoubleSpinBox(verticalLayoutWidget_3);
        scale_kz->setObjectName(QString::fromUtf8("scale_kz"));
        scale_kz->setMinimum(-999.000000000000000);
        scale_kz->setMaximum(999.000000000000000);
        scale_kz->setValue(1.000000000000000);

        gridLayout_5->addWidget(scale_kz, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_5);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 240, 291, 128));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_14 = new QLabel(verticalLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_6->addWidget(label_5, 2, 0, 1, 1);

        label_15 = new QLabel(verticalLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        rotate_x_val = new QDoubleSpinBox(verticalLayoutWidget_2);
        rotate_x_val->setObjectName(QString::fromUtf8("rotate_x_val"));
        rotate_x_val->setMinimum(-999.000000000000000);
        rotate_x_val->setMaximum(999.000000000000000);
        rotate_x_val->setSingleStep(10.000000000000000);

        gridLayout_6->addWidget(rotate_x_val, 0, 1, 1, 1);

        rotate_y_val = new QDoubleSpinBox(verticalLayoutWidget_2);
        rotate_y_val->setObjectName(QString::fromUtf8("rotate_y_val"));
        rotate_y_val->setMinimum(-999.000000000000000);
        rotate_y_val->setMaximum(999.000000000000000);
        rotate_y_val->setSingleStep(10.000000000000000);

        gridLayout_6->addWidget(rotate_y_val, 1, 1, 1, 1);

        rotat_z_val = new QDoubleSpinBox(verticalLayoutWidget_2);
        rotat_z_val->setObjectName(QString::fromUtf8("rotat_z_val"));
        rotat_z_val->setMinimum(-999.000000000000000);
        rotat_z_val->setMaximum(999.000000000000000);
        rotat_z_val->setSingleStep(10.000000000000000);

        gridLayout_6->addWidget(rotat_z_val, 2, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_6);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 291, 128));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_7->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 2, 0, 1, 1);

        dx_val = new QDoubleSpinBox(verticalLayoutWidget);
        dx_val->setObjectName(QString::fromUtf8("dx_val"));
        dx_val->setMinimum(-999.000000000000000);
        dx_val->setMaximum(999.000000000000000);
        dx_val->setSingleStep(10.000000000000000);
        dx_val->setValue(0.000000000000000);

        gridLayout_7->addWidget(dx_val, 0, 1, 1, 1);

        dy_val = new QDoubleSpinBox(verticalLayoutWidget);
        dy_val->setObjectName(QString::fromUtf8("dy_val"));
        dy_val->setMinimum(-999.000000000000000);
        dy_val->setMaximum(999.000000000000000);
        dy_val->setSingleStep(10.000000000000000);

        gridLayout_7->addWidget(dy_val, 1, 1, 1, 1);

        dz_val = new QDoubleSpinBox(verticalLayoutWidget);
        dz_val->setObjectName(QString::fromUtf8("dz_val"));
        dz_val->setMinimum(-999.000000000000000);
        dz_val->setMaximum(999.000000000000000);
        dz_val->setSingleStep(10.000000000000000);

        gridLayout_7->addWidget(dz_val, 2, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_7);

        rotate_btn = new QPushButton(centralwidget);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        rotate_btn->setGeometry(QRect(20, 390, 291, 51));
        scale_btn = new QPushButton(centralwidget);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        scale_btn->setGeometry(QRect(20, 610, 291, 51));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(320, 10, 1021, 941));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 1020, 431, 51));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 1160, 431, 51));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 1280, 431, 51));
        reset_btn = new QPushButton(centralwidget);
        reset_btn->setObjectName(QString::fromUtf8("reset_btn"));
        reset_btn->setGeometry(QRect(20, 760, 141, 61));
        center_btn = new QPushButton(centralwidget);
        center_btn->setObjectName(QString::fromUtf8("center_btn"));
        center_btn->setGeometry(QRect(170, 760, 141, 61));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1353, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(action_open);
        menuFile->addAction(action_save);
        menuFile->addSeparator();
        menuFile->addAction(action_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "Open model", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        transfer_btn->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Dy", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Dx", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Dz", nullptr));
        rotate_btn->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        scale_btn->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        reset_btn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        center_btn->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
