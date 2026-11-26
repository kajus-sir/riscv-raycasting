#include "input.h"
#include "platform.h"

int is_switch_on(int n) {
    return (get_sw() >> n) & 1;
}

int input_move_forward(void)  { return is_switch_on(3) && get_btn(); }
int input_move_backward(void) { return is_switch_on(2) && get_btn(); }
int input_turn_left(void)     { return is_switch_on(1); }
int input_turn_right(void)    { return is_switch_on(0); }
int input_map_view(void)      { return is_switch_on(9); }