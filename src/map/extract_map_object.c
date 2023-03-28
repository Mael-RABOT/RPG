/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** get_texture.c
*/

#include "../../include/prototype.h"

int get_collision(map_object_t **map_object, int id)
{
    int i = 0;
    while (map_object[i] != NULL) {
        if (map_object[i]->id == id) {
            return map_object[i]->collision;
        }
        i += 1;
    }
    return 0;
}

sfTexture *get_texture(map_object_t **map_object, int id)
{
    int i = 0;
    while (map_object[i] != NULL) {
        if (map_object[i]->id == id) {
            return map_object[i]->texture;
        }
        i += 1;
    }
    return NULL;
}
