/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mael.rabot
** File description:
** create_manifest_object.c
*/

#include "../../include/prototype.h"

manifest_t *create_manifest(int id, char *path, int collision)
{
    manifest_t *manifest = malloc(sizeof(manifest_t));
    manifest->id = id;
    manifest->path = my_strdup(path);
    manifest->collision = collision;
    manifest->texture = sfTexture_createFromFile(path, NULL);
    manifest->next_object = NULL;
    return manifest;
}

manifest_t *append_manifest(manifest_t *manifest, int id, char *path,
    int collision)
{
    while (manifest->next_object != NULL) {
        manifest = manifest->next_object;
    }
    manifest->next_object = create_manifest(id, path, collision);
    return manifest->next_object;
}
