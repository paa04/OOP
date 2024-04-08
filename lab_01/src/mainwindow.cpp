#include <QMainWindow>
#include <QFileDialog>
#include "mainwindow.h"

#include <figure.h>

#include "draw.h"
#include "error.h"
#include "events.h"
#include "requests.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 10, ui->graphicsView->height() - 10);

    connect(ui->action_open, SIGNAL(triggered()), this, SLOT(load_clicked()));
    connect(ui->action_save, SIGNAL(triggered()), this, SLOT(save_clicked()));
    connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->transfer_btn, SIGNAL(clicked()), this, SLOT(move_clicked()));
    connect(ui->center_btn, SIGNAL(clicked()), this, SLOT(center_clicked()));
    connect(ui->rotate_btn, SIGNAL(clicked()), this, SLOT(rotate_clicked()));
    connect(ui->scale_btn, SIGNAL(clicked()), this, SLOT(scale_clicked()));
    connect(ui->reset_btn, SIGNAL(clicked()), this, SLOT(reset_clicked()));
}

MainWindow::~MainWindow()
{
    request_t request;
    request.task = EXIT;
    event_handler(request);

    delete ui;
}


int MainWindow::draw_obj(void)
{
    painter_t painter;

    painter.scene = ui->graphicsView->scene();
    painter.scene->clear();
    painter.height = ui->graphicsView->height();
    painter.width = ui->graphicsView->width();

    request_t request;

    request.task = DRAW;
    fill_draw_data(request.draw_data, painter);

    int status = event_handler(request);

    if (status != EXIT_SUCCESS)
        log_error(status);

    return status;
}

void MainWindow::load_clicked(void)
{
    int status = EXIT_SUCCESS;
    QFileDialog dialog(this);
    QStringList filename;
    if (dialog.exec())
        filename = dialog.selectedFiles();
    else
    {
        status = FILE_ERROR;
        if (status != EXIT_SUCCESS)
            log_error(status);
        return;
    }
    const char* name = filename.at(0).toLocal8Bit().constData();

    request_t request;

    request.task = LOAD;

    fill_load_data(request.load_data, name);

    status = event_handler(request);

    if (status == EXIT_SUCCESS)
    {
        request.task = SAVE_BACKUP;
        status = event_handler(request);
        if (status == EXIT_SUCCESS)
            status = draw_obj();
    }

    if (status != EXIT_SUCCESS)
        log_error(status);
}

void MainWindow::save_clicked()
{
    int status = EXIT_SUCCESS;
    QFileDialog dialog(this);
    QStringList filename;
    if (dialog.exec())
        filename = dialog.selectedFiles();
    else
    {
        status = FILE_ERROR;
        if (status != EXIT_SUCCESS)
            log_error(status);
        return;
    }
    const char *name = filename.at(0).toLocal8Bit().constData();

    request_t request;

    request.task = SAVE;
    fill_save_data(request.save_data, name);

    status = event_handler(request);

    if (status != EXIT_SUCCESS)
        log_error(status);
}

double MainWindow::get_data(QDoubleSpinBox* form)
{
    return form->value();
}

void MainWindow::move_clicked()
{
    transform_t transform;

    transform.kx = get_data(ui->dx_val);
    transform.ky = get_data(ui->dy_val);
    transform.kz = get_data(ui->dz_val);

    request_t request;

    request.task = MOVE;
    fill_move_data(request.move_data, transform);

    int status = event_handler(request);

    if (status == EXIT_SUCCESS)
    {
        status = draw_obj();
    }
    else
    {
        log_error(status);
    }
}

void MainWindow::center_clicked()
{
    point_t center;

    center.x_coord = 0;
    center.y_coord = 0;
    center.z_coord = 0;

    request_t request;

    request.task = CENTER;
    fill_center_data(request.center_data, center);

    int status = event_handler(request);

    if (status == EXIT_SUCCESS)
    {
        status = draw_obj();
    }
    else
        log_error(status);

    if (status != EXIT_SUCCESS)
        log_error(status);
}

void MainWindow::rotate_clicked()
{
    transform_t rotate;

    rotate.kx = get_data(ui->rotate_x_val);
    rotate.ky = get_data(ui->rotate_y_val);
    rotate.kz = get_data(ui->rotat_z_val);

    request_t request;

    request.task = FIND_CENTER;
    int status = event_handler(request);

    if (status == EXIT_SUCCESS)
    {
        point_t center;

        retrieve_center_request(request.find_center_data, center);

        request.task = ROTATE;
        fill_rotate_data(request.rotate_data, rotate, center);

        status = event_handler(request);
        if (status == EXIT_SUCCESS)
        {
            status = draw_obj();
            if (status != EXIT_SUCCESS)
                log_error(status);
        }
        else
        {
            log_error(status);
        }
    }
    else
        log_error(status);
}

void MainWindow::scale_clicked()
{
    transform_t scale;

    scale.kx = get_data(ui->scale_kx);
    scale.ky = get_data(ui->scale_ky);
    scale.kz = get_data(ui->scale_kz);


    request_t request;

    request.task = FIND_CENTER;
    int status = event_handler(request);

    if (status == EXIT_SUCCESS)
    {
        point_t center;

        retrieve_center_request(request.find_center_data, center);

        request.task = SCALE;
        fill_scale_data(request.scale_data, scale, center);

        status = event_handler(request);

        if (status == EXIT_SUCCESS)
        {
            status = draw_obj();
            if (status != EXIT_SUCCESS)
                log_error(status);
        }
        else
            log_error(status);
    }
    else
        log_error(status);
}

void MainWindow::reset_clicked()
{
    request_t request;

    request.task = LOAD_BACKUP;

    int status = event_handler(request);

    if (status == EXIT_SUCCESS)
    {
        status = draw_obj();
    }

    if(status != EXIT_SUCCESS)
        log_error(status);

}

void MainWindow::exit()
{
    QApplication::quit();
}