#include "platform.h"
#include "../dtekv-lib.h"
#include "render.h"

void handle_interrupt(unsigned cause) {}

int main(void) {
    print("Hej fran DTEK-V!\n");

    draw_map();

    while (1) { }
}