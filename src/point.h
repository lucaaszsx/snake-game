#ifndef _POINT_H
#define _POINT_H

#include <stdbool.h>

/**
 * @brief Map point structure
 */
typedef struct point {
    int x;
    int y;
} point_t;

bool points_collide(point_t p1, point_t p2);
bool point_collide_arr(point_t point, point_t *ps, int size); // use for arrays of point_t type

#endif