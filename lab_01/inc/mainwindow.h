#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include "ui_MainWindow.h"

#define FILE_ERROR 3

class MainWindow: public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void load_clicked();
        void save_clicked();
        void move_clicked();
        void center_clicked();
        void rotate_clicked();
        void scale_clicked();
        void reset_clicked();
        void exit();

    private:
        int draw_obj();
        static double get_data(QDoubleSpinBox *form);
        Ui::MainWindow *ui;
};


#endif