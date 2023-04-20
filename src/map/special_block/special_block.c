/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-mathieu.borel
** File description:
** special_block.c
*/

#include "../../../include/prototype.h"

static int detect_block_on_tile(const char *pathfile, tile_t *tile)
{
    switch (tile->state) {
        case TELEPORTER:
            connect_teleporter_tile(pathfile, tile); break;
        case NPC:
            return 0;
        default:
            return 0;
    }
    return 0;
}

int special_block(const char *pathfile, layer_t *layer)
{
    int i = 0;
    while (layer->layer[i] != NULL) {
        int j = 0;
        while (layer->layer[i][j]) {
            detect_block_on_tile(pathfile, layer->layer[i][j]);
            j += 1;
        }
        i += 1;
    }
    return 0;
}
