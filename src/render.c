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