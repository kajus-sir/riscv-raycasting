#include "platform.h"
#include "../dtekv-lib.h"

void handle_interrupt(unsigned cause) {}

int main(void) {
    print("Hej fran DTEK-V!\n");
    for (int y = 0; y < SCREEN_H; y++) {
        for (int x = 0; x < SCREEN_W; x++) {
            if (x < SCREEN_W / 2)
                pixel(x, y, RED);
            else
                pixel(x, y, BLUE);
        }
    }

    while (1) { } 
}