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