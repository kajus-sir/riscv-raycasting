// Ansvar: Kajus + Hugo

#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    // Position på kartan, mätt i rutor (1.5 = mitt i ruta 1)
    float x;
    float y;

    // Riktningen spelaren tittar åt (en pil med längd 1)
    float dir_x;
    float dir_y;
} Player;

void player_move_forward(Player *player);
void player_move_backward(Player *player);
void player_turn_left(Player *player);
void player_turn_right(Player *player);

#endif