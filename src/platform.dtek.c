#include "platform.h"

// Framebuffer: varje byte här är en pixel på skärmen
static volatile unsigned char *VGA = (volatile unsigned char *) 0x08000000;

void pixel(int x, int y, unsigned char color) {
    if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H) return; // protect memory
    VGA[y * SCREEN_W + x] = color;
}