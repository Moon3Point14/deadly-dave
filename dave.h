#ifndef DAVE_H
#define DAVE_H

#include "tile.h"

#define DAVE_WALKING_STATE_STANDING  0
#define DAVE_WALKING_STATE_COOLDOWN1_RIGHT  1
#define DAVE_WALKING_STATE_COOLDOWN1_LEFT  2
#define DAVE_WALKING_STATE_COOLDOWN2_RIGHT  3
#define DAVE_WALKING_STATE_COOLDOWN2_LEFT  4
#define DAVE_WALKING_STATE_RIGHT 5
#define DAVE_WALKING_STATE_LEFT 6

#define DAVE_STATE_STANDING    0
#define DAVE_STATE_WALKING     1
#define DAVE_STATE_JUMPING     2
#define DAVE_STATE_FREEFALLING 3
#define DAVE_STATE_DEAD        4

#define DAVE_DIRECTION_FRONTR  0
#define DAVE_DIRECTION_FRONTL  1
#define DAVE_DIRECTION_LEFT    2
#define DAVE_DIRECTION_RIGHT   3

typedef struct dave_struct {
    int x;
    int y;
    int width;
    int height;
    int state;
    int walk_state;
    int step_count;
    int face_direction;
    int jump_state;
    int freefall_direction;
    int has_grail;

    void (*tick)(struct dave_struct *dave,
            tile_t map[TILEMAP_WIDTH * TILEMAP_HEIGHT], int left, int right, int up);
} dave_t;

dave_t* dave_create();

#endif
