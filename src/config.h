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

// Player Size
#define PLAYER_SIZE        5   // spelaren ritas som en 5x5-ruta
#define DIRECTION_LENGTH  10    // hur lång riktningslinjen är (pixlar)

#define CELL_SIZE (SCREEN_H / MAP_H)   

#endif