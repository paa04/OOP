//
// Created by paa04 on 19.03.24.
//

#ifndef REQUESTS_H
#define REQUESTS_H
#include "events.h"

#define WRONG_REQUEST -1

enum TASKS {LOAD, DRAW, MOVE, EXIT, FIND_CENTER, CENTER, ROTATE, SCALE, SAVE_BACKUP, LOAD_BACKUP, SAVE};
int event_handler(request_t &request);

#endif //REQUESTS_H
