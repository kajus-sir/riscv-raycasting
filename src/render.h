#ifndef RENDER_H
#define RENDER_H

#include "player.h"

void draw_column(int x, int height, unsigned char color);
void draw_map(void);
void draw_player(const Player *player);

#endif
