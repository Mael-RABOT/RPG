/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_manifest_object.c
*/

#include "../../include/prototype.h"

map_object_t *create_map_object(int id, char *path, int collision)
{
    map_object_t *manifest = malloc(sizeof(map_object_t));
    manifest->id = id;
    manifest->path = my_strdup(path);
    manifest->collision = collision;
    manifest->texture = sfTexture_createFromFile(path, NULL);
    return manifest;
}

int append_manifest(map_object_t **map_object, int id, char *path,
    int collision)
{
    int i = 0;
    while (map_object[i] != NULL) {
        i += 1;
    }
    map_object[i] = create_map_object(id, path, collision);
    map_object[i + 1] = NULL;
    return 0;
}

map_t *create_map(const char *name, const char *path, map_object_t **map_object)
{
    map_t *map = malloc(sizeof(map_t));
    map->layer = load_layer(path, map_object);
    map->name = my_strdup(name);
    map->path = my_strdup(path);
    map->size = (sfVector2f){0, 0};
    map->spawn = (sfVector2f){0, 0};
    return map;
}
