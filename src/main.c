#include "platform.h"
#include "config.h"
#include "../dtekv-lib.h"
#include "render.h"

void handle_interrupt(unsigned cause) {}

int main(void) {
    print("Hej fran DTEK-V!\n");

    unsigned char colors[] = { RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE };
    int num_colors = sizeof(colors) / sizeof(colors[0]);

    for (int x = 0; x < SCREEN_W; x++) {
        int height = 20 + ((x * 7) % (SCREEN_H + 40)); // Varies from short to taller than SCREEN_H
        unsigned char color = colors[x % num_colors];
        draw_column(x, height, color);
    }


    while (1) { }
}