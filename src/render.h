#ifndef RENDER_H
#define RENDER_H

void draw_column(int x, int height, unsigned char color);
void draw_map(void);

unsigned char wall_color(int type, int side);

#endif
