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