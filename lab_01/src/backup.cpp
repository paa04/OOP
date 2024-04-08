//
// Created by paa04 on 23.03.24.
//
#include "backup.h"

#include <io.h>
#include <string.h>

static void backup_set_name(char *backup_file, figure_t &figure)
{
    strncpy(backup_file, figure.name, MAX_NAME_LEN);
    strcat(backup_file, "_backup.csv");
}

static void copy_figure_name(char *buff, figure_t &figure)
{
    strncpy(buff, figure.name, MAX_NAME_LEN);
}

static void set_figure_name(figure_t &figure, char *name)
{
    strncpy(figure.name, name, MAX_NAME_LEN);
}

int save_backup(figure_t &figure)
{
    char backup_file[MAX_NAME_LEN];
    backup_set_name(backup_file, figure);
    return save_figure(figure, backup_file);
}

int load_backup(figure_t &figure)
{
    int status = EXIT_SUCCESS;
    char name[MAX_NAME_LEN];
    char backup_name[MAX_NAME_LEN];

    backup_set_name(backup_name, figure);
    copy_figure_name(name, figure);

    status = load_figure(figure, backup_name);


    if (status != EXIT_SUCCESS)
        return status;

    set_figure_name(figure, name);

    return status;
}
