#include "render.h"
#include "map.h"
#include "platform.h"
#include "config.h"

void draw_map(void) {
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            unsigned char color;
            if (is_wall(x, y)){
                color = BLACK;
            }
            else{
                color = WHITE;
            }
            draw_rect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
        }
    }
}

void draw_column(int x, int height, unsigned char color) {
    int draw_start = (SCREEN_H - height) / 2;
    int draw_end   = draw_start + height;

    draw_vline(x, 0, draw_start, CEILING_COLOR);
    draw_vline(x, draw_start, draw_end, color);
    draw_vline(x, draw_end, SCREEN_H, FLOOR_COLOR);
}

static unsigned char darken(unsigned char c) {
    unsigned char r = (c >> 5) & 0x7;
    unsigned char g = (c >> 2) & 0x7;
    unsigned char b =  c       & 0x3;
    return ((r >> 1) << 5) | ((g >> 1) << 2) | (b >> 1);
}

unsigned char wall_color(int type, int side) {
    unsigned char color;

    if (type == WALL_RED) {
        color = RED;
    }
    else if (type == WALL_GREEN) {
        color = GREEN;
    }
    else if (type == WALL_BLUE) {
        color = BLUE;
    }
    else {
        color = WHITE;   // okänd typ, 
    }

    if (side == SIDE_Y) {
        color = darken(color);
    }

    return color;
}
