#include "render.h"
#include "map.h"
#include "platform.h"
#include "config.h"
#include "player.h"

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


void draw_player(const Player *player) {
    // 1. Räkna om från rutor till pixlar
    int center_x = (int) (player->x * CELL_SIZE);
    int center_y = (int) (player->y * CELL_SIZE);

    // 2. Rita en liten ruta med spelaren i mitten
    int start_x = center_x - PLAYER_SIZE / 2;
    int start_y = center_y - PLAYER_SIZE / 2;
    draw_rect(start_x, start_y, PLAYER_SIZE, PLAYER_SIZE, RED);

    // 3. Rita en linje i den riktning spelaren tittar
    for (int step = 0; step < DIRECTION_LENGTH; step++) {
        int line_x = center_x + (int) (player->dir_x * step);
        int line_y = center_y + (int) (player->dir_y * step);
        pixel(line_x, line_y, YELLOW);
    }
}