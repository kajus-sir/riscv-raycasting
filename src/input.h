// Ansvar: Kajus

#ifndef INPUT_H
#define INPUT_H

// Alla funktioner svarar ja (1) eller nej (0).
// Vilken switch/knapp som gör vad bestäms bara i input.c.

int input_move_forward(void);
int input_move_backward(void);
int input_turn_left(void);
int input_turn_right(void);

int input_map_view(void);  

#endif