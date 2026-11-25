// Ansvar: Kajus

#include "map.h"

const int map[MAP_H][MAP_W] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

int is_wall(int x, int y){
    int outside_x = (x < 0 || x >= MAP_W);
    int outside_y = (y < 0 || y >= MAP_H);

    if (outside_x || outside_y) {
        return 1;
    }

    if (map[y][x] == 0) {
        return 0;
    }

    return 1;
};
