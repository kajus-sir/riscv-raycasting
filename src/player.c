// Ansvar: Kajus + Hugo

#include "map.h"
#include "player.h"

#define MOVE_SPEED  0.05f  

// Färdiga värden för en sväng på 0.1 radianer (ca 6 grader)
#define TURN_COS    0.9950f
#define TURN_SIN    0.0998f


static void move(Player *player, float distance) {
    float new_x = player->x + player->dir_x * distance;
    float new_y = player->y + player->dir_y * distance;

    // Kolla x och y var för sig, så att spelaren glider längs väggar
    int wall_in_x_direction = is_wall((int) new_x, (int) player->y);
    int wall_in_y_direction = is_wall((int) player->x, (int) new_y);

    if (!wall_in_x_direction) {
        player->x = new_x;
    }
    if (!wall_in_y_direction) {
        player->y = new_y;
    }
}

static void rotate(Player *player, float cos_value, float sin_value) {
    float old_dir_x = player->dir_x;
    float old_dir_y = player->dir_y;

    player->dir_x = old_dir_x * cos_value - old_dir_y * sin_value;
    player->dir_y = old_dir_x * sin_value + old_dir_y * cos_value;
}


void player_move_forward(Player *player)  { move(player,  MOVE_SPEED); }
void player_move_backward(Player *player) { move(player, -MOVE_SPEED); }

void player_turn_right(Player *player) { rotate(player, TURN_COS,  TURN_SIN); }
void player_turn_left(Player *player)  { rotate(player, TURN_COS, -TURN_SIN); }