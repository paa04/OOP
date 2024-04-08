//
// Created by paa04 on 20.03.24.
//
#include <QMessageBox>
#include "error.h"

#include <io.h>

#include "mainwindow.h"

void log_error(int error)
{
    switch (error)
    {
    case NOT_ENOUGH_POINTS:
        QMessageBox::critical(NULL, "Ошибка", "Недостаточно точек");
        break;
    case OPEN_FILE_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка открытия файла");
        break;
    case FILE_DATA_ERROR:
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при работе с файлом");
        break;
    case SMALL_SCALE:
        QMessageBox::critical(NULL, "Ошибка", "Слишком маленькие"
                                              " коэфиценты масштабирования");
        break;
    default:
        QMessageBox::critical(NULL, "Ошибка", "Неизвестная ошибка");
    }
}
