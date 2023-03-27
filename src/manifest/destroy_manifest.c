/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** destroy_manifest.c
*/

#include "../../include/prototype.h"

int destroy_manifest(manifest_t *manifest)
{
    if (manifest == NULL)
        return 0;
    free(manifest->path);
    sfTexture_destroy(manifest->texture);
    destroy_manifest(manifest->next_object);
    free(manifest);
    return 0;
}
