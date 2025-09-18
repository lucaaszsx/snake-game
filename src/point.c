#include "point.h"

bool points_collide(point_t p1, point_t p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool point_collide_arr(point_t point, point_t *ps, int size) {
    bool collide = false;

    for (int i = 0; i < size; i++) {
        point_t curr_point = ps[i];

        if (points_collide(point, curr_point)) {
            collide = true;
            break;
        }
    }

    return collide;
}