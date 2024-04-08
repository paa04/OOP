//
// Created by paa04 on 19.03.24.
//
#include "requests.h"

#include "figure.h"

int event_handler(request_t &request)
{
    static figure_t figure = init_figure();
    int status = EXIT_SUCCESS;
    switch (request.task)
    {
        case LOAD:
            status = load(figure, request.load_data);
            break;
        case SAVE:
            status = save(figure, request.save_data);
            break;
        case DRAW:
            status = draw(figure, request.draw_data);
            break;
        case MOVE:
            status = move(figure, request.move_data);
            break;
        case FIND_CENTER:
            status = find_center(figure, request.find_center_data);
            break;
        case CENTER:
            status = center(figure, request.center_data);
            break;
        case ROTATE:
            status = rotate(figure, request.rotate_data);
            break;
        case SCALE:
            status = scale(figure, request.scale_data);
            break;
        case SAVE_BACKUP:
            status = save_backup_event(figure);
            break;
        case LOAD_BACKUP:
            status = load_backup_event(figure);
            break;
        case EXIT:
            destroy_figure(figure);
            break;
        default:
            status = WRONG_REQUEST;
    }

    return status;
}
