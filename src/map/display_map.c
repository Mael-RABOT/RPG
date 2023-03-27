/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** display_map.c
*/

#include "../../include/prototype.h"

int display_map(sfRenderWindow *window, map_t *map)
{
    int i = 0;
    while (map->map[i] != NULL) {
        int j = 0;
        while (map->map[i][j] != NULL) {
            sfRenderWindow_drawSprite(window, map->map[i][j]->tile, NULL);
            j += 1;
        }
        i += 1;
    }
    return 0;
}
