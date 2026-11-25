#ifndef PLATFORM_H
#define PLATFORM_H

#define SCREEN_W 320
#define SCREEN_H 240

void pixel(int x, int y, unsigned char color);
void draw_rect(int start_x, int start_y, int width, int height, unsigned char color);

#endif