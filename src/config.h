#ifndef CONFIG_H
#define CONFIG_H

// ===== Färger (1 byte = RRRGGGBB) =====
#define BLACK      0x00
#define WHITE      0xFF
#define RED        0xE0
#define GREEN      0x1C
#define BLUE       0x03
#define YELLOW     0xFC
#define CYAN       0x1F
#define MAGENTA    0xE3
#define GRAY       0x92
#define DARK_GRAY  0x49

// Tak och golv
#define CEILING_COLOR  DARK_GRAY
#define FLOOR_COLOR    GRAY

// ===== Väggtyper (värdena i map[][], 0 = tom ruta) =====
#define WALL_RED    1
#define WALL_GREEN  2
#define WALL_BLUE   3

// ===== Väggsidor (vilken rutnätslinje strålen träffade) =====
#define SIDE_X  0   // korsade en vertikal linje -> väggen vetter öst/väst, full ljusstyrka
#define SIDE_Y  1   // korsade en horisontell linje -> väggen vetter nord/syd, mörkare

#define CELL_SIZE (SCREEN_H / MAP_H)   // 240 / 12 = 20 pixlar per ruta

#endif