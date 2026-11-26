#include "platform.h"
#include "config.h"
#include "../dtekv-lib.h"
#include "render.h"

void test () {
    unsigned char colors[] = { RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE };
    int num_colors = sizeof(colors) / sizeof(colors[0]);

    for (int x = 0; x < SCREEN_W; x++) {
        int height = 20 + ((x * 7) % (SCREEN_H + 40)); // Varies from short to taller than SCREEN_H
        unsigned char color = colors[x % num_colors];
        draw_column(x, height, color);
    }
}

// Delar skärmen i 8 band à 40 px: varje väggtyp först med SIDE_X (ljus),
// sedan med SIDE_Y (mörk). Sista paret är en okänd typ och ska bli vitt/grått.
void test_wall_color () {
    int types[] = { WALL_RED, WALL_GREEN, WALL_BLUE, 99 };
    int num_types = sizeof(types) / sizeof(types[0]);
    int band_w = SCREEN_W / (num_types * 2);

    for (int x = 0; x < SCREEN_W; x++) {
        int band = x / band_w;
        int type = types[band / 2];
        int side = (band % 2 == 0) ? SIDE_X : SIDE_Y;
        draw_column(x, 160, wall_color(type, side));
    }
}

// Räknar sekunder på lysdioderna. Ska öka med exakt 1 per sekund,
// oavsett vad huvudloopen gör (avbrotten sköter tiden).
void test_timer () {
    timer_init();
    while (1) {
        set_leds(timer_ticks / TICKS_PER_SEC);
    }
}

int main(void) {
    print("Hej fran DTEK-V!\n");

    // draw_map();
    // test();
    test_wall_color();
    test_timer();

    while (1) { }
}