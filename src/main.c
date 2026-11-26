#include "platform.h"
#include "../dtekv-lib.h"
#include "render.h"


void handle_interrupt(unsigned cause) {}

Player player = { 1.5f, 1.5f, 1.0f, 0.0f };   

int main(void) {
    print("Hej fran DTEK-V!\n");

    while (1) { 
        if (input_move_forward())  player_move_forward(&player);
        if (input_move_backward()) player_move_backward(&player);
        if (input_turn_left())     player_turn_left(&player);
        if (input_turn_right())    player_turn_right(&player);

        draw_player(&player);
        draw_map();
    }
}