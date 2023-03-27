/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** get_texture.c
*/

#include "../../include/prototype.h"

int get_collision(manifest_t *manifest, int id)
{
    while (manifest != NULL) {
        if (manifest->id == id) {
            return manifest->collision;
        }
        manifest = manifest->next_object;
    }
    return 0;
}

sfTexture *get_texture(manifest_t *manifest, int id)
{
    while (manifest != NULL) {
        if (manifest->id == id) {
            return manifest->texture;
        }
        manifest = manifest->next_object;
    }
    return NULL;
}
