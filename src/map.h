// Ansvar: Kajus

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define MAP_W 12
#define MAP_H 8

extern const int map[MAP_H][MAP_W];  
int is_wall(int x, int y);

#endif