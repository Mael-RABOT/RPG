/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** detect_spawn.c
*/

#include "../../include/prototype.h"

static int detect_spawn_line(map_t *map, int i, int j)
{
    int k = 0;
    while (map->layer[i]->layer[j][k] != NULL) {
        if (map->layer[i]->layer[j][k]->collision == 3) {
            map->spawn = (sfVector2f){k, j};
        }
        k += 1;
    }
    return 0;
}

int detect_spawn(map_t *map)
{
    int i = 0;
    while (map->layer[i] != NULL) {
        int j = 0;
        while (map->layer[i]->layer[j] != NULL) {
            detect_spawn_line(map, i, j);
            j += 1;
        }
        i += 1;
    }
    return 0;
}
