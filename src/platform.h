#ifndef PLATFORM_H
#define PLATFORM_H

#define SCREEN_W 320
#define SCREEN_H 240

// Färger: 1 byte = RRRGGGBB
#define RED   0xE0   // 111 000 00
#define BLUE  0x03   // 000 000 11

void pixel(int x, int y, unsigned char color);

#endif